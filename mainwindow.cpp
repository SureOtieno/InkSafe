#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QMessageBox>
#include <QMediaRecorder>
#include <QAudioInput>
#include <QMediaCaptureSession>
#include <QMediaFormat>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTimer>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    mediaRecorder(nullptr),
    captureSession(nullptr),
    player(nullptr),
    audioOutput(nullptr),
    isRecording(false),
    currentEntryId(-1),
    isPlaying(false)
{
    ui->setupUi(this);

    audioInput = nullptr;

    createConnection();

    // Initialize media player
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.8);

    // Connect error signals
    connect(player, &QMediaPlayer::errorOccurred, this, [this](){
        qDebug() << "Player error:" << player->errorString();
        QMessageBox::warning(this, "Playback Error", player->errorString());
    });

    connect(ui->listWidget, &QListWidget::itemClicked,
            this, &MainWindow::onEntryClicked);

    connect(ui->playButton, &QPushButton::clicked, this, [this]() {
        if (currentEntryId != -1) {
            QSqlQuery query;
            query.prepare("SELECT id FROM journals.media_assets WHERE entry_id = ? AND media_type = 'audio' LIMIT 1");
            query.addBindValue(currentEntryId);
            if (query.exec() && query.next()) {
                playAudioFromDB(query.value("id").toInt());
            }
        }
    });

    connect(player, &QMediaPlayer::errorOccurred, this, [](QMediaPlayer::Error error, const QString &errorString) {
        qDebug() << "MediaPlayer error:" << errorString;
    });

    connect(player, &QMediaPlayer::positionChanged, this, [=](qint64 pos) {
        ui->audioSlider->setValue(pos);
    });

    connect(player, &QMediaPlayer::durationChanged, this, [=](qint64 duration) {
        ui->audioSlider->setMaximum(duration);
    });

    // Optional: allow slider control
    connect(ui->audioSlider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);

    connect(ui->pushButton, &QPushButton::clicked,
            this, &MainWindow::onSaveButtonClicked);
    connect(ui->tlineEdit, &QLineEdit::textChanged,
            this, &MainWindow::updateSaveButtonState);
    connect(ui->entryTEdit, &QTextEdit::textChanged,
            this, &MainWindow::updateSaveButtonState);
    connect(ui->dateFrom, &QDateEdit::dateChanged, this, &MainWindow::updateFilterButtonState);
    connect(ui->dateTo, &QDateEdit::dateChanged, this, &MainWindow::updateFilterButtonState);
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &MainWindow::updateFilterButtonState);
    connect(ui->filterButton, &QPushButton::clicked, this, [this]() {
        applyFilters(ui->searchLineEdit->text());
    });
    connect(ui->recordButton, &QPushButton::clicked, this, &MainWindow::onRecordButtonClicked);
    connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::onPlayButtonClicked);

}


bool MainWindow::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("InkSafe");
    db.setUserName("postgres");
    db.setPassword("Kaliente@#25");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error",
                              "Failed to connect: " + db.lastError().text());
        return false;
    }
    return true;
}

void MainWindow::onRecordButtonClicked()
{
    if (isRecording) {
        stopRecording();
        return;
    }

    startRecording();
}

void MainWindow::onPlayButtonClicked()
{
    if (!currentAudioPath.isEmpty()) {
        playAudio(currentAudioPath);

    } else {
        QMessageBox::warning(this, "Playback", "No audio file available to play");
    }


    if (isPlaying) {
        player->pause();
        ui->playButton->setText("Play");
        isPlaying = false;
    } else {
        player->play();
        ui->playButton->setText("Pause");
        isPlaying = true;
    }


}

void MainWindow::startRecording()
{
    cleanupMediaResources(); // cleans previous session

    currentAudioPath = QStandardPaths::writableLocation(QStandardPaths::TempLocation) +
                       "/recording_" + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss") + ".wav";

    // Only create a new one if it doesn't exist
    if (!audioInput) {
        audioInput = new QAudioInput(this);
    }

    captureSession = new QMediaCaptureSession(this);
    mediaRecorder = new QMediaRecorder(this);

    // Configure format
    QMediaFormat format;
    format.setFileFormat(QMediaFormat::Wave);
    format.setAudioCodec(QMediaFormat::AudioCodec::Wave);
    mediaRecorder->setMediaFormat(format);

    captureSession->setAudioInput(audioInput);
    captureSession->setRecorder(mediaRecorder);
    mediaRecorder->setOutputLocation(QUrl::fromLocalFile(currentAudioPath));

    connect(mediaRecorder, &QMediaRecorder::recorderStateChanged, this,
            [this](QMediaRecorder::RecorderState state){
                if (state == QMediaRecorder::StoppedState) {
                    QString title = ui->audioTitle->text().trimmed();
                    if (title.isEmpty()) {
                        title = "Recording " + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm");
                    }
                    saveAudioToDB(currentAudioPath, title);
                    ui->recordButton->setText("Record");
                    isRecording = false;
                }
            });

    mediaRecorder->record();
    isRecording = true;
    ui->recordButton->setText("Stop Recording");
    QMessageBox::information(this, "Recording", "Recording started...");
}


void MainWindow::stopRecording()
{
    if (mediaRecorder) {
        mediaRecorder->stop();
    }
}

void MainWindow::playAudio(const QString& filePath)
{
    if (!player || !audioOutput) {
        QMessageBox::critical(this, "Error", "Audio playback is not initialized");
        return;
    }


    if (!QFile::exists(filePath)) {
        QMessageBox::warning(this, "Error", "Audio file does not exist");
        return;
    }

    player->stop();
    player->setSource(QUrl::fromLocalFile(filePath));

    player->play();
}

void MainWindow::saveAudioToDB(const QString& filePath, const QString& title)
{

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Error", "Title and content cannot be empty");
        return;
    }

    bool isNew = ui->pushButton->property("isNew").toBool();
    if (isNew) {
        if (!isFileNameUnique(title)) {
            QMessageBox::warning(this, "Error", "Title must be unique");
            return;
        }
    }

    if (currentEntryId == -1) {
        QMessageBox::warning(this, "Error", "You must select or create a journal entry before recording audio.");
        return;
    }


    QFile file(filePath);  // Assuming this was supposed to be filePath, not tempFilePath
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open audio file.");
        return;
    }

    QByteArray audioData = file.readAll();
    file.close();

    if (audioData.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Audio file is empty.");
        return;
    }

    QSqlQuery query;
    if (!query.prepare(R"(
        INSERT INTO journals.media_assets
        (entry_id, media_type, file_name, mime_type, file_data, created_at)
        VALUES (?, ?, ?, ?, ?, NOW())
    )")) {
        qDebug() << "Query prepare failed:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to prepare audio insert query");
        return;
    }

    query.addBindValue(currentEntryId);
    query.addBindValue("audio");
    query.addBindValue(title);
    query.addBindValue("audio/mpeg");
    query.addBindValue(audioData);

    qDebug() << "Executing audio insert query...";
    if (!query.exec()) {
        qDebug() << "DB insert failed:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to save audio");
    } else {
        if (isNew) {
            // Fetch last inserted ID
            QSqlQuery idQuery("SELECT currval(pg_get_serial_sequence('journals.journal_entries','id'))");
            if (idQuery.next()) {
                currentEntryId = idQuery.value(0).toInt();
            }
        }

        displayJournalEntries();
        QMessageBox::information(this, "Success", isNew ? "New entry created" : "Entry updated");
    }

}


bool MainWindow::isFileNameUnique(const QString& title)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM journals.media_assets where file_name = :title");
    query.bindValue(":title", title);

    if (!query.exec()){
        qDebug() << "Query failed: " << query.lastError();
        return false;
    }
    if (query.next()) {
        int count = query.value(0).toInt();
        return (count == 0);
    }
    return false;
}

bool MainWindow::isTitleUnique(const QString& title)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM journals.journal_entries where title = :title");
    query.bindValue(":title", title);

    if (!query.exec()){
        qDebug() << "Query failed: " << query.lastError();
        return false;
    }
    if (query.next()) {
        int count = query.value(0).toInt();
        return (count == 0);
    }
    return false;
}

bool MainWindow::isTitleUniquenId(const QString& title, int excludeId)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM journals.journal_entries WHERE title = :title AND id != :excludeId");
    query.bindValue(":title", title);
    query.bindValue(":excludeId", excludeId);

    return (query.exec() && query.next() && query.value(0).toInt() == 0);
}

bool MainWindow::isFileNameUniqueId(const QString& title, int excludeId)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM journals.media_assets WHERE file_name = :title AND id != :excludeId");
    query.bindValue(":title", title);
    query.bindValue(":excludeId", excludeId);

    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError();
        return false;
    }

    return query.next() && query.value(0).toInt() == 0;
}

QString MainWindow::saveAudioFromDBToTempFile(const QByteArray& audioData)
{
    QString tempPath = QStandardPaths::writableLocation(QStandardPaths::TempLocation) + "/entry_audio.wav";
    QFile tempFile(tempPath);
    if (tempFile.open(QIODevice::WriteOnly)) {
        tempFile.write(audioData);
        tempFile.close();
        return tempPath;
    } else {
        qDebug() << "Failed to save audio to temp file.";
        return QString();
    }
}

void MainWindow::playAudioFromDB(int mediaId)
{
    QSqlQuery query;
    query.prepare("SELECT file_data, mime_type FROM journals.media_assets WHERE id = ?");
    query.addBindValue(mediaId);

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Playback Error", "Could not load audio from database");
        return;  // early return on failure
    }

    QByteArray audioData = query.value("file_data").toByteArray();
    QString mimeType = query.value("mime_type").toString();

    // Decide file extension based on MIME type
    QString extension = ".wav";  // Default
    if (mimeType.contains("ogg")) extension = ".ogg";
    else if (mimeType.contains("mp3")) extension = ".mp3";

    QString tempPath = QStandardPaths::writableLocation(QStandardPaths::TempLocation) +
                       "/playback_" + QString::number(mediaId) + extension;

    QFile tempFile(tempPath);
    if (!tempFile.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Error", "Could not create temporary playback file");
        return;  // fail safely
    }

    tempFile.write(audioData);
    tempFile.close();

    playAudio(tempPath);
}


void MainWindow::onEntryClicked(QListWidgetItem *item)
{
    int entryId = item->data(Qt::UserRole).toInt();
    currentEntryId = entryId;

    QSqlQuery query;
    query.prepare("SELECT title, entry_text, content_type, created_at FROM journals.journal_entries WHERE id = ?");
    query.addBindValue(entryId);

    if (query.exec() && query.next()) {
        QString title = query.value("title").toString();
        QString content = query.value("entry_text").toString();
        QString contentType = query.value("content_type").toString();
        QDateTime date = query.value("created_at").toDateTime();

        ui->tlineEdit->setText(title);
        ui->entryTEdit->setPlainText(content);
        ui->entryTEdit->setVisible(contentType == "text");

        ui->pushButton->setProperty("isNew", false);
        ui->pushButton->setText("Update Entry");

        // ✅ NEW: Always check for media, regardless of contentType
        QSqlQuery mediaQuery;
        mediaQuery.prepare(R"(
            SELECT id, media_type FROM journals.media_assets
            WHERE entry_id = ? ORDER BY created_at DESC LIMIT 1
        )");
        mediaQuery.addBindValue(entryId);

        if (mediaQuery.exec() && mediaQuery.next()) {
            int mediaId = mediaQuery.value("id").toInt();
            QString mediaType = mediaQuery.value("media_type").toString();

            if (mediaType == "audio") {
                playAudioFromDB(mediaId);
            } else {
                // TODO: Handle other media types later if needed
                qDebug() << "Media exists but is not audio. Media type:" << mediaType;
            }
        } else {
            qDebug() << "No media found for entry";
        }
    } else {
        qDebug() << "Failed to load entry:" << query.lastError();
    }
}



void MainWindow::applyFilters(const QString &filterText)
{
    // QDate fromDate = ui->dateFrom->date();
    // QDate toDate = ui->dateTo->date();

    // // Assume this is your default UI range (e.g., today to today)
    // QDate defaultFrom = QDate(2000, 1, 1);
    // QDate defaultTo = QDate::currentDate();


    // bool useDateFilter = fromDate != defaultFrom || toDate != defaultTo;
    bool useTextFilter = !filterText.trimmed().isEmpty();

    // // Validate date range if applicable
    // if (useDateFilter && fromDate > toDate) {
    //     QMessageBox::warning(this, "Invalid Date Range",
    //                          "End date cannot be before start date");
    //     return;
    // }

    QString sql = "SELECT id, title, created_at FROM journals.journal_entries WHERE 1=1";
    QSqlQuery query;

    if (useTextFilter) {
        sql += " AND title ILIKE :search_term";
    }

    // if (useDateFilter) {
    //     sql += " AND created_at BETWEEN :start_date AND :end_date";
    // }

    sql += " ORDER BY created_at DESC";

    if (!query.prepare(sql)) {
        qDebug() << "Query preparation failed:" << query.lastError();
        return;
    }

    if (useTextFilter) {
        query.bindValue(":search_term", "%" + filterText + "%");
    }

    // if (useDateFilter) {
    //     query.bindValue(":start_date", QDateTime(fromDate, QTime(0, 0)).toString(Qt::ISODate));
    //     query.bindValue(":end_date", QDateTime(toDate, QTime(23, 59, 59)).toString(Qt::ISODate));

    // }

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError();
        QMessageBox::critical(this, "Database Error",
                              "Failed to filter entries: " + query.lastError().text());
        return;
    }

    ui->listWidget->clear();
    while (query.next()) {
        int id = query.value("id").toInt();
        QString title = query.value("title").toString();
        QDateTime createdAt = query.value("created_at").toDateTime();

        QListWidgetItem *item = new QListWidgetItem(
            QString("%1 - %2").arg(createdAt.toString("MMM d"), title));
        item->setData(Qt::UserRole, id);
        ui->listWidget->addItem(item);
    }
}


void MainWindow::updateFilterButtonState() {
    QDate defaultFrom = QDate(2000, 1, 1);
    QDate defaultTo = QDate::currentDate();

    bool hasText = !ui->searchLineEdit->text().trimmed().isEmpty();
    bool hasCustomDates = ui->dateFrom->date() != defaultFrom || ui->dateTo->date() != defaultTo;

    ui->filterButton->setEnabled(hasText || hasCustomDates);
}

void MainWindow::displayJournalEntries()
{
    ui->listWidget->clear();

    QSqlQuery query("SELECT e.id, e.title, e.created_at, "
       "EXISTS (SELECT 1 FROM journals.media_assets m "
                "WHERE m.entry_id = e.id AND m.media_type = 'audio' "
                " ) AS has_audio "
                "FROM journals.journal_entries e"
                "ORDER BY e.created_at DESC");

    while (query.next()) {
        int id = query.value("id").toInt();
        QString title = query.value("title").toString();
        QDateTime date = query.value("created_at").toDateTime();
        bool hasAudio = query.value("has_audio").toBool();

        QString label = QString("%1 - %2").arg(date.toString("MMM d"), title);
        if (hasAudio) {
            label += " 🎵";  // 🎧 or 🔊 also good options
        }

        QListWidgetItem *item = new QListWidgetItem(label);
        item->setData(Qt::UserRole, id);
        ui->listWidget->addItem(item);
    }

    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError();
        return;
    }

}


void MainWindow::setupSaveButton()
{
    ui->pushButton->setText("Save Entry");
    ui->pushButton->setEnabled(false);
    ui->pushButton->setProperty("isNew", true);

}

void MainWindow::setupPlayButton()
{
    ui->playButton->setText("Play");
    ui->playButton->setEnabled(false);
    ui->playButton->setProperty("isNew", true);

}

void MainWindow::updateSaveButtonState()
{
    bool hasText = !ui->entryTEdit->toPlainText().trimmed().isEmpty();
    bool hasTitle = !ui->tlineEdit->text().trimmed().isEmpty();

    ui->pushButton->setEnabled(hasText && hasTitle);

}
void MainWindow::updatePlayButtonState()
{
    if (isPlaying) {
        ui->playButton->setText("Pause");
    } else {
        ui->playButton->setText("Play");
    }

}

void MainWindow::onSaveButtonClicked()
{
    QString title = ui->tlineEdit->text().trimmed();
    QString content = ui->entryTEdit->toPlainText().trimmed();

    if (title.isEmpty() || content.isEmpty()) {
        QMessageBox::warning(this, "Error", "Title and content cannot be empty");
        return;
    }

    bool isNew = ui->pushButton->property("isNew").toBool();
    if (isNew) {
        if (!isTitleUnique(title)) {
            QMessageBox::warning(this, "Error", "Title must be unique");
            return;
        }
    } else {
        if (!isTitleUniquenId(title, currentEntryId)) {
            QMessageBox::warning(this, "Error", "Title must be unique");
            return;
        }
    }

    QSqlQuery query;
    QDateTime now = QDateTime::currentDateTime();

    if (isNew) {
        query.prepare(R"(INSERT INTO journals.journal_entries
                    (title, entry_text, content_type, created_at, updated_at)
                    VALUES (:title, :entry_text, :content_type, NOW(), NOW())
                )");

        query.bindValue(":title", title);
        query.bindValue(":entry_text", content);
        query.bindValue(":content_type", "text");

    } else {
        query.prepare(R"(UPDATE journals.journal_entries
                        SET title = :title,
                            entry_text = :entry_text,
                            content_type = :content_type,
                            updated_at = NOW()
                        WHERE id = :id
                    )");

        query.bindValue(":title", title);
        query.bindValue(":entry_text", content);
        query.bindValue(":content_type", "text");
        query.bindValue(":id", currentEntryId);

    }


    if (query.exec()) {
        displayJournalEntries();
        if (isNew) {
            QMessageBox::information(this, "Success", "New entry created");
        } else {
            QMessageBox::information(this, "Success", "Entry updated");
        }
    }else {
        qDebug() << "Insert failed:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to save audio");
    }

    ui->tlineEdit->clear();
    ui->entryTEdit->clear();
    setupSaveButton();
    currentEntryId = -1;

}

void MainWindow::onSaveMediaButtonClicked()
{
    if (currentAudioPath.isEmpty()) {
        QMessageBox::warning(this, "Error", "No recording available to save");
        return;
    }

    QString title = ui->audioTitle->text().trimmed();
    if (title.isEmpty()) {
        title = "Recording " + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm");
    }

    // Check for unique title
    if (!isFileNameUniqueId(title, currentEntryId)) {
        QMessageBox::warning(this, "Error", "This title already exists. Please choose a unique title.");
        return;
    }

    // Read audio file
    QFile audioFile(currentAudioPath);
    if (!audioFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Could not open audio file for saving");
        return;
    }

    // Prepare database query
    QSqlQuery query;
    query.prepare(
        "INSERT INTO journals.media_assets "
        "(entry_id, media_type, file_name, mime_type, file_data, created_at) "
        "VALUES (?, ?, ?, ?, ?, NOW())"
        );

    query.addBindValue(currentEntryId);
    query.addBindValue("audio");
    query.addBindValue(title);
    query.addBindValue("audio/wav");
    query.addBindValue(audioFile.readAll());

    QSqlDatabase::database().commit();

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error",
                              "Failed to save recording: " + query.lastError().text());
        return;
    }
    QSqlDatabase::database().rollback();

    QMessageBox::information(this, "Success", "Recording saved successfully");
    displayJournalEntries();  // Refresh the media list
    currentAudioPath.clear();
    ui->audioTitle->clear();
}

void MainWindow::cleanupMediaResources()
{
    if (player) {
        player->stop();
        // No need to disconnect unless you're reassigning signals/slots
    }

    if (mediaRecorder) {
        if (mediaRecorder->recorderState() == QMediaRecorder::RecordingState) {
            mediaRecorder->stop();
        }
        mediaRecorder->deleteLater();
        mediaRecorder = nullptr;
    }

    if (captureSession) {
        captureSession->deleteLater();
        captureSession = nullptr;
    }

    if (audioInput) {
        audioInput->deleteLater();
        audioInput = nullptr;
    }

    qputenv("QT_DEBUG_PLUGINS", QByteArray("1"));


}




MainWindow::~MainWindow()
{
    cleanupMediaResources();
    delete ui;
}




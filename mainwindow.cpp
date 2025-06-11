#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createConnection();
    displayEntries();


    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onSaveButtonClicked);
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

bool MainWindow::isTitleUnique(const QString& title)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM journal_entries where title = :title");
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

void MainWindow::displayEntries()
{
    ui->listWidget->clear(); // Clear existing display

    QSqlQuery query("SELECT title, created_at FROM journal_entries ORDER BY created_at DESC");

    while (query.next()) {
        int id = query.value(0).toInt();
        QString title = query.value(1).toString();
        QString preview = query.value(2).toString().left(50) + "...";
        QDateTime date = query.value(3).toDateTime();

        QListWidgetItem *item = new QListWidgetItem(
            QString("%1\n%2\n%3")
                .arg(title)
                .arg(date.toString("MMM d, yyyy h:mm ap"))
                .arg(preview));

        item->setData(Qt::UserRole, id); // Store ID for retrieval
        ui->listWidget->addItem(item);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSaveButtonClicked() {
    QString title = ui->tlineEdit->text();
    QString text = ui->entryTEdit->toPlainText();
    QDateTime timestamp = QDateTime::currentDateTime();
    if (text.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Empty Entry", "Please write something before saving.");
        return;
    }
    if (title.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Title cannot be empty");
        return;
    }
    if (!isTitleUnique(title)){
        QMessageBox::warning(this, "Warning", "This title already exists. Choose another one.");
    }

    QSqlQuery query;
    query.prepare("INSERT INTO journal_entries (title, entry_text, created_at) "
                  "VALUES (:title, :entry_text, :created_at)");
    query.bindValue(":title", title);
    query.bindValue(":entry_text", text);
    query.bindValue(":created_at", timestamp);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
        return;
    }else{
        QMessageBox::information(this, "Success", "Entry saved successfully");
        displayEntries();
    }

    ui->entriesLabel->setText("Entries saved at " + timestamp.toString());
    ui->tlineEdit->clear();
    ui->entryTEdit->clear();

}


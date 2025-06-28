#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include <QScopedPointer>
#include <QMediaRecorder>
#include <QMediaPlayer>
#include <QListWidgetItem>
#include <QAudioInput>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool createConnection();
    void displayJournalEntries();
    void onSearchTextChanged(const QString &text);

private slots:
    void updateSaveButtonState();
    void onSaveButtonClicked();
    void onEntryClicked(QListWidgetItem *item);
    void applyFilters(const QString &filterText);
    void updateFilterButtonState();
    void onRecordButtonClicked();
    void saveAudioToDB(const QString& filePath, const QString& title);
    void playAudio(const QString& filePath);
    void startRecording();
    void stopRecording();
    void onPlayButtonClicked();
    void playAudioFromDB(int mediaId);
    void onSaveMediaButtonClicked();
    QString saveAudioFromDBToTempFile(const QByteArray& audioData);

private:
    // UI
    Ui::MainWindow *ui;

    // Database
    int currentEntryId;

    // Media Components
    QPointer<QMediaRecorder> mediaRecorder;
    QPointer<QMediaCaptureSession> captureSession;
    QPointer<QMediaPlayer> player;
    QPointer<QAudioOutput> audioOutput;
    QPointer<QAudioInput> audioInput;

    // State
    QString currentAudioPath;
    bool isRecording;
    bool isPlaying;

    // Helper methods
    void setupSaveButton();
    void setupPlayButton();
    void updatePlayButtonState();
    void cleanupMediaResources();
    bool isTitleUniquenId(const QString& title, int excludeId = -1);
    bool isTitleUnique(const QString& title);
    bool isFileNameUnique(const QString& title);
    bool isFileNameUniqueId(const QString& title, int excludeId = -1);
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

#include <QMainWindow>

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
    void displayEntries();


private slots:
    void onSaveButtonClicked();  // Action-oriented naming

private:
    Ui::MainWindow *ui;
    bool isTitleUnique(const QString& title);
};

#endif // MAINWINDOW_H


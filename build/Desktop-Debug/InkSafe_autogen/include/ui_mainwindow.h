/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLineEdit *tlineEdit;
    QTextEdit *entryTEdit;
    QLabel *entriesLabel;
    QLabel *create_edit;
    QListWidget *listWidget;
    QLineEdit *searchLineEdit;
    QLabel *from;
    QLabel *to;
    QLabel *search;
    QPushButton *filterButton;
    QDateEdit *dateFrom;
    QDateEdit *dateTo;
    QPushButton *recordButton;
    QLabel *recordingLabel;
    QPushButton *playButton;
    QLineEdit *audioTitle;
    QSlider *audioSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1338, 702);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 620, 121, 31));
        tlineEdit = new QLineEdit(centralwidget);
        tlineEdit->setObjectName("tlineEdit");
        tlineEdit->setGeometry(QRect(20, 50, 451, 41));
        entryTEdit = new QTextEdit(centralwidget);
        entryTEdit->setObjectName("entryTEdit");
        entryTEdit->setGeometry(QRect(20, 100, 451, 511));
        entriesLabel = new QLabel(centralwidget);
        entriesLabel->setObjectName("entriesLabel");
        entriesLabel->setGeometry(QRect(800, 150, 161, 31));
        create_edit = new QLabel(centralwidget);
        create_edit->setObjectName("create_edit");
        create_edit->setGeometry(QRect(20, 10, 161, 31));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(790, 190, 521, 421));
        searchLineEdit = new QLineEdit(centralwidget);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(970, 10, 341, 26));
        from = new QLabel(centralwidget);
        from->setObjectName("from");
        from->setGeometry(QRect(900, 50, 41, 18));
        to = new QLabel(centralwidget);
        to->setObjectName("to");
        to->setGeometry(QRect(920, 100, 20, 20));
        search = new QLabel(centralwidget);
        search->setObjectName("search");
        search->setGeometry(QRect(890, 10, 51, 18));
        filterButton = new QPushButton(centralwidget);
        filterButton->setObjectName("filterButton");
        filterButton->setGeometry(QRect(1200, 150, 101, 31));
        dateFrom = new QDateEdit(centralwidget);
        dateFrom->setObjectName("dateFrom");
        dateFrom->setGeometry(QRect(970, 50, 71, 27));
        dateTo = new QDateEdit(centralwidget);
        dateTo->setObjectName("dateTo");
        dateTo->setGeometry(QRect(970, 100, 71, 27));
        recordButton = new QPushButton(centralwidget);
        recordButton->setObjectName("recordButton");
        recordButton->setGeometry(QRect(490, 100, 161, 31));
        recordingLabel = new QLabel(centralwidget);
        recordingLabel->setObjectName("recordingLabel");
        recordingLabel->setGeometry(QRect(500, 10, 161, 31));
        playButton = new QPushButton(centralwidget);
        playButton->setObjectName("playButton");
        playButton->setGeometry(QRect(490, 190, 101, 31));
        audioTitle = new QLineEdit(centralwidget);
        audioTitle->setObjectName("audioTitle");
        audioTitle->setGeometry(QRect(490, 50, 281, 41));
        audioSlider = new QSlider(centralwidget);
        audioSlider->setObjectName("audioSlider");
        audioSlider->setGeometry(QRect(490, 160, 281, 16));
        audioSlider->setMaximum(100);
        audioSlider->setPageStep(1);
        audioSlider->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1338, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QString());
        tlineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Title your thoughts...", nullptr));
        entryTEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Your thoughts here...", nullptr));
        entriesLabel->setText(QCoreApplication::translate("MainWindow", "My Thoughts", nullptr));
        create_edit->setText(QCoreApplication::translate("MainWindow", "Create/Edit", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search title...", nullptr));
        from->setText(QCoreApplication::translate("MainWindow", "From:", nullptr));
        to->setText(QCoreApplication::translate("MainWindow", "To:", nullptr));
        search->setText(QCoreApplication::translate("MainWindow", "Search:", nullptr));
        filterButton->setText(QCoreApplication::translate("MainWindow", "Filter/Refresh", nullptr));
        recordButton->setText(QCoreApplication::translate("MainWindow", "Record", nullptr));
        recordingLabel->setText(QCoreApplication::translate("MainWindow", "Record Thoughts", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        audioTitle->setPlaceholderText(QCoreApplication::translate("MainWindow", "Title your thoughts...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

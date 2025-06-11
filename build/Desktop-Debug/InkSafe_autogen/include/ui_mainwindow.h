/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QListWidget *listWidget;
    QLabel *entriesLabel;
    QLabel *create_edit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1335, 662);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 520, 88, 26));
        tlineEdit = new QLineEdit(centralwidget);
        tlineEdit->setObjectName(QString::fromUtf8("tlineEdit"));
        tlineEdit->setGeometry(QRect(20, 50, 571, 41));
        entryTEdit = new QTextEdit(centralwidget);
        entryTEdit->setObjectName(QString::fromUtf8("entryTEdit"));
        entryTEdit->setGeometry(QRect(13, 110, 581, 391));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(655, 51, 631, 551));
        entriesLabel = new QLabel(centralwidget);
        entriesLabel->setObjectName(QString::fromUtf8("entriesLabel"));
        entriesLabel->setGeometry(QRect(660, 10, 161, 31));
        create_edit = new QLabel(centralwidget);
        create_edit->setObjectName(QString::fromUtf8("create_edit"));
        create_edit->setGeometry(QRect(20, 10, 161, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1335, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        entriesLabel->setText(QCoreApplication::translate("MainWindow", "My Entries", nullptr));
        create_edit->setText(QCoreApplication::translate("MainWindow", "Create/Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

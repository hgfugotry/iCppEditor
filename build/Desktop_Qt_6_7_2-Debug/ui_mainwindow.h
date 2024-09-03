/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFileOpen_O;
    QAction *actionFileSave_S;
    QAction *actionFileSaveAs_A;
    QAction *actionBuildCompile_C;
    QAction *actionBuildSet_S;
    QAction *actionNewProject_N;
    QAction *action_H;
    QAction *action_C;
    QAction *action_R;
    QAction *action_D;
    QAction *actionOpenProject_O;
    QAction *actionAddProjectFile_A;
    QAction *actionSettingsFont_F;
    QAction *actionSettingsColor_C;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *fileNameGroupBox;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QMenu *menuFile_F;
    QMenu *menuBuild_B;
    QMenu *menuProject_P;
    QMenu *menuSettings_S;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(881, 534);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionFileOpen_O = new QAction(MainWindow);
        actionFileOpen_O->setObjectName("actionFileOpen_O");
        actionFileSave_S = new QAction(MainWindow);
        actionFileSave_S->setObjectName("actionFileSave_S");
        actionFileSaveAs_A = new QAction(MainWindow);
        actionFileSaveAs_A->setObjectName("actionFileSaveAs_A");
        actionBuildCompile_C = new QAction(MainWindow);
        actionBuildCompile_C->setObjectName("actionBuildCompile_C");
        actionBuildSet_S = new QAction(MainWindow);
        actionBuildSet_S->setObjectName("actionBuildSet_S");
        actionNewProject_N = new QAction(MainWindow);
        actionNewProject_N->setObjectName("actionNewProject_N");
        action_H = new QAction(MainWindow);
        action_H->setObjectName("action_H");
        action_C = new QAction(MainWindow);
        action_C->setObjectName("action_C");
        action_R = new QAction(MainWindow);
        action_R->setObjectName("action_R");
        action_D = new QAction(MainWindow);
        action_D->setObjectName("action_D");
        actionOpenProject_O = new QAction(MainWindow);
        actionOpenProject_O->setObjectName("actionOpenProject_O");
        actionAddProjectFile_A = new QAction(MainWindow);
        actionAddProjectFile_A->setObjectName("actionAddProjectFile_A");
        actionSettingsFont_F = new QAction(MainWindow);
        actionSettingsFont_F->setObjectName("actionSettingsFont_F");
        actionSettingsColor_C = new QAction(MainWindow);
        actionSettingsColor_C->setObjectName("actionSettingsColor_C");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        fileNameGroupBox = new QGroupBox(centralwidget);
        fileNameGroupBox->setObjectName("fileNameGroupBox");
        fileNameGroupBox->setStyleSheet(QString::fromUtf8("background:rgb(245,225,245);"));
        horizontalLayout_3 = new QHBoxLayout(fileNameGroupBox);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        plainTextEdit = new QPlainTextEdit(fileNameGroupBox);
        plainTextEdit->setObjectName("plainTextEdit");
        QFont font;
        font.setFamilies({QString::fromUtf8("Noto Sans Hatran")});
        font.setPointSize(13);
        font.setBold(true);
        plainTextEdit->setFont(font);
        plainTextEdit->setStyleSheet(QString::fromUtf8("background:rgb(13, 13, 6);\n"
"color:rgb(255,255,255);"));
        plainTextEdit->setLineWrapMode(QPlainTextEdit::LineWrapMode::NoWrap);

        horizontalLayout_3->addWidget(plainTextEdit);


        horizontalLayout_2->addWidget(fileNameGroupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 881, 27));
        menuFile_F = new QMenu(menubar);
        menuFile_F->setObjectName("menuFile_F");
        menuBuild_B = new QMenu(menubar);
        menuBuild_B->setObjectName("menuBuild_B");
        menuProject_P = new QMenu(menubar);
        menuProject_P->setObjectName("menuProject_P");
        menuSettings_S = new QMenu(menubar);
        menuSettings_S->setObjectName("menuSettings_S");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile_F->menuAction());
        menubar->addAction(menuBuild_B->menuAction());
        menubar->addAction(menuProject_P->menuAction());
        menubar->addAction(menuSettings_S->menuAction());
        menuFile_F->addAction(actionFileOpen_O);
        menuFile_F->addAction(actionFileSave_S);
        menuFile_F->addAction(actionFileSaveAs_A);
        menuBuild_B->addAction(actionBuildCompile_C);
        menuBuild_B->addAction(actionBuildSet_S);
        menuProject_P->addAction(actionNewProject_N);
        menuProject_P->addAction(actionOpenProject_O);
        menuProject_P->addSeparator();
        menuSettings_S->addAction(actionSettingsFont_F);
        menuSettings_S->addAction(actionSettingsColor_C);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionFileOpen_O->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", nullptr));
#if QT_CONFIG(shortcut)
        actionFileOpen_O->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFileSave_S->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", nullptr));
#if QT_CONFIG(shortcut)
        actionFileSave_S->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFileSaveAs_A->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(&A)", nullptr));
#if QT_CONFIG(shortcut)
        actionFileSaveAs_A->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionBuildCompile_C->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\257\221\345\271\266\350\277\220\350\241\214(&C)", nullptr));
#if QT_CONFIG(shortcut)
        actionBuildCompile_C->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionBuildSet_S->setText(QCoreApplication::translate("MainWindow", "\351\205\215\347\275\256\347\274\226\350\257\221\351\200\211\351\241\271(&S)", nullptr));
#if QT_CONFIG(shortcut)
        actionBuildSet_S->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Alt+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNewProject_N->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256(&N)", nullptr));
#if QT_CONFIG(shortcut)
        actionNewProject_N->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+N", nullptr));
#endif // QT_CONFIG(shortcut)
        action_H->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\244\264\346\226\207\344\273\266(&H)", nullptr));
        action_C->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\272\220\346\226\207\344\273\266(&C)", nullptr));
        action_R->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\265\204\346\272\220\346\226\207\344\273\266(&R)", nullptr));
        action_D->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244(&D)", nullptr));
        actionOpenProject_O->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\351\241\271\347\233\256(&O)", nullptr));
#if QT_CONFIG(shortcut)
        actionOpenProject_O->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAddProjectFile_A->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240(&A)", nullptr));
        actionSettingsFont_F->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223(&F)", nullptr));
        actionSettingsColor_C->setText(QCoreApplication::translate("MainWindow", "\351\242\234\350\211\262(&C)", nullptr));
        fileNameGroupBox->setTitle(QCoreApplication::translate("MainWindow", "File Name", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("MainWindow", "\347\244\276\344\274\232\344\270\273\344\271\211\346\240\270\345\277\203\344\273\267\345\200\274\350\247\202\357\274\232\n"
"\345\257\214\345\274\272 \346\260\221\344\270\273 \346\226\207\346\230\216 \345\222\214\350\260\220\n"
"\350\207\252\347\224\261 \345\271\263\347\255\211 \345\205\254\346\255\243 \346\263\225\346\262\273\n"
"\347\210\261\345\233\275 \346\225\254\344\270\232 \350\257\232\344\277\241 \345\217\213\345\226\204", nullptr));
        menuFile_F->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menuBuild_B->setTitle(QCoreApplication::translate("MainWindow", "\346\236\204\345\273\272(&B)", nullptr));
        menuProject_P->setTitle(QCoreApplication::translate("MainWindow", "\351\241\271\347\233\256(&P)", nullptr));
        menuSettings_S->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256(&S)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

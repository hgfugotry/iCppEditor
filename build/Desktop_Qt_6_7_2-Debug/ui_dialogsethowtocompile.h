/********************************************************************************
** Form generated from reading UI file 'dialogsethowtocompile.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSETHOWTOCOMPILE_H
#define UI_DIALOGSETHOWTOCOMPILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogSetHowToCompile
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *CompilerComboBox;
    QLabel *Label;
    QComboBox *optimizeChoiceComboBox;
    QLabel *Label_2;
    QLineEdit *outputLineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *commitButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *DialogSetHowToCompile)
    {
        if (DialogSetHowToCompile->objectName().isEmpty())
            DialogSetHowToCompile->setObjectName("DialogSetHowToCompile");
        DialogSetHowToCompile->resize(639, 148);
        verticalLayout = new QVBoxLayout(DialogSetHowToCompile);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(DialogSetHowToCompile);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        CompilerComboBox = new QComboBox(DialogSetHowToCompile);
        CompilerComboBox->addItem(QString());
        CompilerComboBox->addItem(QString());
        CompilerComboBox->setObjectName("CompilerComboBox");

        formLayout->setWidget(0, QFormLayout::FieldRole, CompilerComboBox);

        Label = new QLabel(DialogSetHowToCompile);
        Label->setObjectName("Label");

        formLayout->setWidget(1, QFormLayout::LabelRole, Label);

        optimizeChoiceComboBox = new QComboBox(DialogSetHowToCompile);
        optimizeChoiceComboBox->addItem(QString());
        optimizeChoiceComboBox->addItem(QString());
        optimizeChoiceComboBox->addItem(QString());
        optimizeChoiceComboBox->addItem(QString());
        optimizeChoiceComboBox->addItem(QString());
        optimizeChoiceComboBox->setObjectName("optimizeChoiceComboBox");

        formLayout->setWidget(1, QFormLayout::FieldRole, optimizeChoiceComboBox);

        Label_2 = new QLabel(DialogSetHowToCompile);
        Label_2->setObjectName("Label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, Label_2);

        outputLineEdit = new QLineEdit(DialogSetHowToCompile);
        outputLineEdit->setObjectName("outputLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, outputLineEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(378, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        commitButton = new QPushButton(DialogSetHowToCompile);
        commitButton->setObjectName("commitButton");

        horizontalLayout->addWidget(commitButton);

        cancelButton = new QPushButton(DialogSetHowToCompile);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DialogSetHowToCompile);

        QMetaObject::connectSlotsByName(DialogSetHowToCompile);
    } // setupUi

    void retranslateUi(QDialog *DialogSetHowToCompile)
    {
        DialogSetHowToCompile->setWindowTitle(QCoreApplication::translate("DialogSetHowToCompile", "\351\205\215\347\275\256\347\274\226\350\257\221\351\200\211\351\241\271", nullptr));
        label->setText(QCoreApplication::translate("DialogSetHowToCompile", "\347\274\226\350\257\221\345\231\250", nullptr));
        CompilerComboBox->setItemText(0, QCoreApplication::translate("DialogSetHowToCompile", "g++", nullptr));
        CompilerComboBox->setItemText(1, QCoreApplication::translate("DialogSetHowToCompile", "gcc", nullptr));

        Label->setText(QCoreApplication::translate("DialogSetHowToCompile", "\344\274\230\345\214\226\351\200\211\351\241\271", nullptr));
        optimizeChoiceComboBox->setItemText(0, QCoreApplication::translate("DialogSetHowToCompile", "O0(Debug)", nullptr));
        optimizeChoiceComboBox->setItemText(1, QCoreApplication::translate("DialogSetHowToCompile", "Og", nullptr));
        optimizeChoiceComboBox->setItemText(2, QCoreApplication::translate("DialogSetHowToCompile", "O1", nullptr));
        optimizeChoiceComboBox->setItemText(3, QCoreApplication::translate("DialogSetHowToCompile", "O2(Release)", nullptr));
        optimizeChoiceComboBox->setItemText(4, QCoreApplication::translate("DialogSetHowToCompile", "O3", nullptr));

        Label_2->setText(QCoreApplication::translate("DialogSetHowToCompile", "\350\276\223\345\207\272", nullptr));
        outputLineEdit->setText(QCoreApplication::translate("DialogSetHowToCompile", "a.out", nullptr));
        commitButton->setText(QCoreApplication::translate("DialogSetHowToCompile", "\347\241\256\345\256\232(&O)", nullptr));
        cancelButton->setText(QCoreApplication::translate("DialogSetHowToCompile", "\345\217\226\346\266\210(&C)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSetHowToCompile: public Ui_DialogSetHowToCompile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSETHOWTOCOMPILE_H

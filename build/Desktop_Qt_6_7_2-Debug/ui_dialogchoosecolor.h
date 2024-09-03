/********************************************************************************
** Form generated from reading UI file 'dialogchoosecolor.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCHOOSECOLOR_H
#define UI_DIALOGCHOOSECOLOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogChooseColor
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *rlabel;
    QLabel *glabel;
    QLabel *blabel;
    QSpinBox *rspinBox;
    QSpinBox *gspinBox;
    QSpinBox *bspinBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *commitButton;

    void setupUi(QDialog *DialogChooseColor)
    {
        if (DialogChooseColor->objectName().isEmpty())
            DialogChooseColor->setObjectName("DialogChooseColor");
        DialogChooseColor->resize(400, 142);
        DialogChooseColor->setMinimumSize(QSize(400, 142));
        DialogChooseColor->setMaximumSize(QSize(400, 142));
        QFont font;
        font.setFamilies({QString::fromUtf8("Ubuntu Sans")});
        DialogChooseColor->setFont(font);
        formLayoutWidget = new QWidget(DialogChooseColor);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 0, 371, 95));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        rlabel = new QLabel(formLayoutWidget);
        rlabel->setObjectName("rlabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, rlabel);

        glabel = new QLabel(formLayoutWidget);
        glabel->setObjectName("glabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, glabel);

        blabel = new QLabel(formLayoutWidget);
        blabel->setObjectName("blabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, blabel);

        rspinBox = new QSpinBox(formLayoutWidget);
        rspinBox->setObjectName("rspinBox");
        rspinBox->setMaximum(255);

        formLayout->setWidget(0, QFormLayout::FieldRole, rspinBox);

        gspinBox = new QSpinBox(formLayoutWidget);
        gspinBox->setObjectName("gspinBox");
        gspinBox->setMaximum(255);

        formLayout->setWidget(1, QFormLayout::FieldRole, gspinBox);

        bspinBox = new QSpinBox(formLayoutWidget);
        bspinBox->setObjectName("bspinBox");
        bspinBox->setMaximum(255);

        formLayout->setWidget(2, QFormLayout::FieldRole, bspinBox);

        widget = new QWidget(DialogChooseColor);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(220, 100, 168, 32));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);

        commitButton = new QPushButton(widget);
        commitButton->setObjectName("commitButton");

        horizontalLayout->addWidget(commitButton);


        retranslateUi(DialogChooseColor);

        QMetaObject::connectSlotsByName(DialogChooseColor);
    } // setupUi

    void retranslateUi(QDialog *DialogChooseColor)
    {
        DialogChooseColor->setWindowTitle(QCoreApplication::translate("DialogChooseColor", "\347\273\231\344\275\240\347\202\271\351\242\234\350\211\262", nullptr));
        rlabel->setText(QCoreApplication::translate("DialogChooseColor", "R", nullptr));
        glabel->setText(QCoreApplication::translate("DialogChooseColor", "G", nullptr));
        blabel->setText(QCoreApplication::translate("DialogChooseColor", "B", nullptr));
        cancelButton->setText(QCoreApplication::translate("DialogChooseColor", "\345\217\226\346\266\210(&C)", nullptr));
        commitButton->setText(QCoreApplication::translate("DialogChooseColor", "\347\241\256\345\256\232(&O)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogChooseColor: public Ui_DialogChooseColor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCHOOSECOLOR_H

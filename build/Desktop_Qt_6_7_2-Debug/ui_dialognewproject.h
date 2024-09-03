/********************************************************************************
** Form generated from reading UI file 'dialognewproject.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGNEWPROJECT_H
#define UI_DIALOGNEWPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogNewProject
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *projectNameEdit;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *projectPathEdit;
    QPushButton *browsePathButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *commitButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *DialogNewProject)
    {
        if (DialogNewProject->objectName().isEmpty())
            DialogNewProject->setObjectName("DialogNewProject");
        DialogNewProject->resize(606, 293);
        verticalLayout_2 = new QVBoxLayout(DialogNewProject);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(DialogNewProject);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        projectNameEdit = new QLineEdit(DialogNewProject);
        projectNameEdit->setObjectName("projectNameEdit");

        verticalLayout->addWidget(projectNameEdit);

        label = new QLabel(DialogNewProject);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        projectPathEdit = new QLineEdit(DialogNewProject);
        projectPathEdit->setObjectName("projectPathEdit");

        horizontalLayout->addWidget(projectPathEdit);

        browsePathButton = new QPushButton(DialogNewProject);
        browsePathButton->setObjectName("browsePathButton");

        horizontalLayout->addWidget(browsePathButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 106, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        commitButton = new QPushButton(DialogNewProject);
        commitButton->setObjectName("commitButton");

        horizontalLayout_2->addWidget(commitButton);

        cancelButton = new QPushButton(DialogNewProject);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_2->addWidget(cancelButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(DialogNewProject);

        QMetaObject::connectSlotsByName(DialogNewProject);
    } // setupUi

    void retranslateUi(QDialog *DialogNewProject)
    {
        DialogNewProject->setWindowTitle(QCoreApplication::translate("DialogNewProject", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        label_2->setText(QCoreApplication::translate("DialogNewProject", "\351\241\271\347\233\256\345\220\215\347\247\260\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("DialogNewProject", "\350\267\257\345\276\204\357\274\232", nullptr));
        browsePathButton->setText(QCoreApplication::translate("DialogNewProject", "\346\265\217\350\247\210...", nullptr));
        commitButton->setText(QCoreApplication::translate("DialogNewProject", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("DialogNewProject", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogNewProject: public Ui_DialogNewProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGNEWPROJECT_H

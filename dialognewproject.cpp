#include "dialognewproject.h"
#include "ui_dialognewproject.h"

#include<QFileDialog>

DialogNewProject::DialogNewProject(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogNewProject)
{
    ui->setupUi(this);

    connect(ui->commitButton,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(reject()));
    connect(ui->browsePathButton,SIGNAL(clicked()),this,SLOT(do_browsePathButton_clicked()));
}

DialogNewProject::~DialogNewProject()
{
    delete ui;
}

DialogNewProject::ProjectMessage DialogNewProject::inputMessage()
{
    return {ui->projectNameEdit->text(),ui->projectPathEdit->text()};
}

void DialogNewProject::do_browsePathButton_clicked()
{
    ui->projectPathEdit->setText(QFileDialog::getExistingDirectory(this,"项目路径",QDir::currentPath()));
}

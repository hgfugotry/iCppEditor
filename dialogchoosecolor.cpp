#include "dialogchoosecolor.h"
#include "ui_dialogchoosecolor.h"

DialogChooseColor::DialogChooseColor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogChooseColor)
{
    ui->setupUi(this);

    connect(ui->commitButton,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(reject()));
}

DialogChooseColor::~DialogChooseColor()
{
    delete ui;
}

DialogChooseColor::RGB DialogChooseColor::inputMessage()
{
    return {ui->rspinBox->value(),ui->gspinBox->value(),ui->bspinBox->value()};
}

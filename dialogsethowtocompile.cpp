#include "dialogsethowtocompile.h"
#include "ui_dialogsethowtocompile.h"

DialogSetHowToCompile::DialogSetHowToCompile(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogSetHowToCompile)
{
    ui->setupUi(this);
}

DialogSetHowToCompile::~DialogSetHowToCompile()
{
    delete ui;
}

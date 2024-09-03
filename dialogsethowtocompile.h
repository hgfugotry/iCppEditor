#ifndef DIALOGSETHOWTOCOMPILE_H
#define DIALOGSETHOWTOCOMPILE_H

#include <QDialog>

namespace Ui {
class DialogSetHowToCompile;
}

class DialogSetHowToCompile : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSetHowToCompile(QWidget *parent = nullptr);
    ~DialogSetHowToCompile();

private:
    Ui::DialogSetHowToCompile *ui;
};

#endif // DIALOGSETHOWTOCOMPILE_H

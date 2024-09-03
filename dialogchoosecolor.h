#ifndef DIALOGCHOOSECOLOR_H
#define DIALOGCHOOSECOLOR_H

#include <QDialog>

namespace Ui {
class DialogChooseColor;
}

class DialogChooseColor : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChooseColor(QWidget *parent = nullptr);
    ~DialogChooseColor();
    struct RGB
    {
        int r;
        int g;
        int b;
    };
    RGB inputMessage();
private:
    Ui::DialogChooseColor *ui;
};

#endif // DIALOGCHOOSECOLOR_H

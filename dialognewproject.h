#ifndef DIALOGNEWPROJECT_H
#define DIALOGNEWPROJECT_H

#include<QDialog>
#include<QString>

namespace Ui {
class DialogNewProject;
}

class DialogNewProject : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewProject(QWidget *parent = nullptr);
    ~DialogNewProject();
    struct ProjectMessage
    {
        QString projectName;
        QString projectPath;
    };
    ProjectMessage inputMessage();
private:
    Ui::DialogNewProject *ui;
private slots:
    void do_browsePathButton_clicked();
};

#endif // DIALOGNEWPROJECT_H

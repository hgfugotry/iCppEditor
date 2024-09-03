#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QFileDialog>
#include<QTreeWidgetItem>
#include<QString>
#include<QDockWidget>
#include<QTreeWidget>
#include<QInputDialog>
#include<QFontDialog>
#include<QMessageBox>
#include<QColorDialog>
#include<QVBoxLayout>
#include<QFont>
#include<QDir>
#include<QFileInfo>
#include<QPalette>

#include"project.h"
#include"ProjectRightMenu.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    enum itemType{TYPEITEM=1001,FILEITEM};
private:
    Ui::MainWindow *ui;
    QString currentFilePath;
    QString currentProjectPath;
    Project* project;

    ProjectRightMenu* projectRightMenu;
    class ProjectDockWidget
    {
    public:
        QDockWidget* dockWidget;
        QWidget* dockWidgetContext;
        QTreeWidget* treeProjectWidget;
        QVBoxLayout* vBoxLayout;
    public:
        ProjectDockWidget(QWidget* parent=nullptr);
        ProjectDockWidget(const ProjectDockWidget& right);
        ProjectDockWidget& operator=(const ProjectDockWidget& right);
        ~ProjectDockWidget();
    };

    ProjectDockWidget projectDockWidget;
    enum TreeColumnNumber{
        HEADER=0,
        SOURCE=1,
        OTHERS=2
    };
private:
    void addProjectFile(int mode);
    QString fileSaveAs();
    void fileSave(QString filePath);
    void setNullEditor();
    void setEditor(QString filePath);
private slots:
    void do_File_Open_triggered();
    void do_File_Save_triggered();
    void do_File_SaveAs_triggered();

    void do_Project_New_triggered();
    void do_Project_Open_triggered();

    void do_SettingsSeries_triggered();

    void do_treeProjectWidget_customContextMenuRequested(const QPoint& pos);
    void do_treeProjectWidget_currentItemChanged(QTreeWidgetItem* current,QTreeWidgetItem* previous);

    void do_fileChanged(QString currentFilePath);
    void do_projectChanged(QString currentProjectPath);

    void do_projectRightMenu_addFileSeries_triggered();
    void do_projectRightMenu_deleteFileSeries_triggered();
signals:
    void fileChanged(QString currentFilePath);
    void projectChanged(QString currentProjectPath);
};

#endif // MAINWINDOW_H

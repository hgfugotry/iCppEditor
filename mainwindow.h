#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include<vector>

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
#include<QPlainTextEdit>
#include<QHBoxLayout>
#include<QPushButton>

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
    class ProjectDockWidget
    {
    public:
        QDockWidget* dockWidget;
        QWidget* dockWidgetContext;
        QTreeWidget* treeProjectWidget;
        QVBoxLayout* vBoxLayout;
    public:
        ProjectDockWidget(QWidget* parent=nullptr);
        ProjectDockWidget(const ProjectDockWidget& right);//显式禁用
        ProjectDockWidget& operator=(const ProjectDockWidget& right);//显式禁用
        ~ProjectDockWidget();
    };
    class TabPlainTextEditWidget
    {
    public:
        QWidget* tab;
        QPlainTextEdit* plainTextEdit;
        QVBoxLayout* vBoxLayout;
        QString fileName;
        bool loaded=false;
    public:
        TabPlainTextEditWidget(QString fileName_);
        TabPlainTextEditWidget(const TabPlainTextEditWidget& right);//显式禁用
        TabPlainTextEditWidget& operator=(const TabPlainTextEditWidget& right);//显式禁用
        ~TabPlainTextEditWidget();
    };

    Ui::MainWindow *ui;
    QString currentProjectPath;
    Project* project;

    ProjectRightMenu* projectRightMenu;
    ProjectDockWidget projectDockWidget;

    QTabWidget* tabWidget;
    std::vector<TabPlainTextEditWidget*> tabPlainTextEditWidgets;

    enum TreeColumnNumber{
        HEADER=0,
        SOURCE=1,
        OTHERS=2
    };
private:
    void iniUi();
    void iniConnects();
    void addProjectFile(int mode);
    QString fileSaveAs();
    void fileSave(QString fileName);
    void deleteCurrentStar();
    bool reportIfHasNotAnyFileOpen();
    void setNullEditor();
    void setEditor(QString filePath);
    void setEditorFont();
    void setEditorColor();
    void newTabWidgetWithPlainTextEdit(QString fileName);
    void delTabWidgetWithPlainTextEdit(QString fileName);
    void delTabWidgetWithPlainTextEdit(int index);
    int seekTabFile(QString fileName);

    static void addFolderItem(QTreeWidgetItem* parentItem,QString name,int itemType);
    static void setFileItem(QTreeWidgetItem* fileItem,QString name,QString absPathName);
private slots:
    void do_File_Open_triggered();
    void do_File_Save_triggered();
    void do_File_SaveAs_triggered();
    void do_Build_Settings_triggered();
    void do_Project_New_triggered();
    void do_Project_Open_triggered();
    void do_SettingsSeries_triggered();

    void do_tabWidget_tabCloseRequested(int index);
    void do_plainTextEdits_textChanged();

    void do_treeProjectWidget_customContextMenuRequested(const QPoint& pos);
    void do_treeProjectWidget_currentItemChanged(QTreeWidgetItem* current,QTreeWidgetItem* previous);

    void do_projectChanged(QString currentProjectPath);

    void do_projectRightMenu_addFileSeries_triggered();
    void do_projectRightMenu_deleteFileSeries_triggered();
signals:
    void projectChanged(QString currentProjectPath);
};

#endif // MAINWINDOW_H

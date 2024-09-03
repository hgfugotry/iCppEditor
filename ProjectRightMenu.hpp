#ifndef PROJECTRIGHTMENU_HPP
#define PROJECTRIGHTMENU_HPP

#include<QMenu>

class ProjectRightMenu:public QMenu
{
    Q_OBJECT
public:
    QMenu* addFileMenu;
    QAction* addHeader;
    QAction* addSource;
    QAction* addOthers;

    QMenu* deleteFileMenu;
    QAction* deleteFile;
    QAction* removeFile;
public:
    ProjectRightMenu(QWidget* parent=nullptr);
    ~ProjectRightMenu();
};

#endif // PROJECTRIGHTMENU_HPP

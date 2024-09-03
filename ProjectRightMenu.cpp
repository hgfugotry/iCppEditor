#include"ProjectRightMenu.hpp"

#include<QTreeWidgetItem>

ProjectRightMenu::ProjectRightMenu(QWidget* parent):QMenu(parent)
{
    addFileMenu=new QMenu;
    addHeader=new QAction;
    addSource=new QAction;
    addOthers=new QAction;
    addFileMenu->setTitle("添加");
    addHeader->setText("头文件");
    addSource->setText("源文件");
    addOthers->setText("其他文件");
    addFileMenu->addAction(addHeader);
    addFileMenu->addAction(addSource);
    addFileMenu->addAction(addOthers);

    deleteFileMenu=new QMenu;
    deleteFile=new QAction;
    removeFile=new QAction;
    deleteFileMenu->setTitle("删除");
    deleteFile->setText("删除");
    removeFile->setText("从项目中移除");
    deleteFileMenu->addAction(deleteFile);
    deleteFileMenu->addAction(removeFile);

    this->addMenu(addFileMenu);
    this->addSeparator();
    this->addMenu(deleteFileMenu);
}

ProjectRightMenu::~ProjectRightMenu()
{
    delete addFileMenu;
    delete addHeader;
    delete addSource;
    delete addOthers;

    delete deleteFileMenu;
    delete deleteFile;
    delete removeFile;
}

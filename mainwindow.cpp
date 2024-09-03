#include<iostream>
#include"ProjectRightMenu.hpp"
#include"dialognewproject.h"
#include"dialogchoosecolor.h"
#include"mainwindow.h"
#include"ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea,projectDockWidget.dockWidget);

    projectRightMenu=new ProjectRightMenu(this);

    connect(ui->actionFileOpen_O,SIGNAL(triggered()),this,SLOT(do_File_Open_triggered()));//菜单栏->打开文件
    connect(ui->actionFileSave_S,SIGNAL(triggered()),this,SLOT(do_File_Save_triggered()));//菜单栏->保存文件
    connect(ui->actionFileSaveAs_A,SIGNAL(triggered()),this,SLOT(do_File_SaveAs_triggered()));//菜单栏->另存为文件
    connect(ui->actionNewProject_N,SIGNAL(triggered()),this,SLOT(do_Project_New_triggered()));//菜单栏->新建项目
    connect(ui->actionOpenProject_O,SIGNAL(triggered()),this,SLOT(do_Project_Open_triggered()));//菜单栏->打开项目
    connect(ui->actionSettingsFont_F,SIGNAL(triggered()),this,SLOT(do_SettingsSeries_triggered()));//菜单栏->设置字体
    connect(ui->actionSettingsColor_C,SIGNAL(triggered()),this,SLOT(do_SettingsSeries_triggered()));//菜单栏->设置颜色

    connect(this,SIGNAL(fileChanged(QString)),this,SLOT(do_fileChanged(QString)));//文本编辑器文件发生改变
    connect(this,SIGNAL(projectChanged(QString)),this,SLOT(do_projectChanged(QString)));//打开的项目发生改变

    connect(projectDockWidget.treeProjectWidget,SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)),this,SLOT(do_treeProjectWidget_currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)));

    //项目右键菜单
    connect(projectRightMenu->addHeader,SIGNAL(triggered()),this,SLOT(do_projectRightMenu_addFileSeries_triggered()));
    connect(projectRightMenu->addSource,SIGNAL(triggered()),this,SLOT(do_projectRightMenu_addFileSeries_triggered()));
    connect(projectRightMenu->addOthers,SIGNAL(triggered()),this,SLOT(do_projectRightMenu_addFileSeries_triggered()));
    connect(projectRightMenu->deleteFile,SIGNAL(triggered()),this,SLOT(do_projectRightMenu_deleteFileSeries_triggered()));
    connect(projectRightMenu->removeFile,SIGNAL(triggered()),this,SLOT(do_projectRightMenu_deleteFileSeries_triggered()));

    //连接显示项目右键菜单的槽
    connect(projectDockWidget.treeProjectWidget,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(do_treeProjectWidget_customContextMenuRequested(const QPoint&)));//项目树右键菜单
}

MainWindow::~MainWindow()
{
    delete ui;
    delete projectRightMenu;
}

MainWindow::ProjectDockWidget::ProjectDockWidget(QWidget* parent)
{
    //设置项目停靠区域
    dockWidget=new QDockWidget(parent);
    dockWidgetContext=new QWidget;
    treeProjectWidget=new QTreeWidget(dockWidgetContext);
    vBoxLayout=new QVBoxLayout;
    vBoxLayout->addWidget(treeProjectWidget);
    dockWidget->setFeatures(QDockWidget::DockWidgetFeatures(0x6));
    dockWidget->setAllowedAreas(Qt::DockWidgetArea::AllDockWidgetAreas);
    treeProjectWidget->setStyleSheet("background:rgb(255,245,255);");
    dockWidget->setWindowTitle("项目");
    dockWidget->setWidget(dockWidgetContext);
    dockWidgetContext->setLayout(vBoxLayout);
    treeProjectWidget->setContextMenuPolicy(Qt::CustomContextMenu);
}

MainWindow::ProjectDockWidget::~ProjectDockWidget()
{
    delete vBoxLayout;
    delete treeProjectWidget;
    delete dockWidgetContext;
    delete dockWidget;
}

//打开文件，发射fileChanged
void MainWindow::do_File_Open_triggered()
{
    //打开文件选择对话框
    QString fileName=QFileDialog::getOpenFileName(nullptr,"打开文件",QDir::currentPath(),"C源文件(*.c *.h);;C++源文件(*.cpp *.cxx *.cc *.hpp *.h);;其他文件(*.*)");
    if(!fileName.isNull())emit fileChanged(fileName);
}

//菜单保存槽，发射fileChanged
void MainWindow::do_File_Save_triggered()
{
    if(!currentFilePath.isNull())
        fileSave(currentFilePath);
    else
        fileSaveAs();
}

//菜单另存为槽，发射fileChanged
void MainWindow::do_File_SaveAs_triggered()
{
    fileSaveAs();
}

//显示项目右键菜单
void MainWindow::do_treeProjectWidget_customContextMenuRequested(const QPoint& pos)
{
    Q_UNUSED(pos);
    if(!currentProjectPath.isNull())
        projectRightMenu->exec(QCursor::pos());
    else
    {
        QMenu* menu=new QMenu(this);
        menu->addAction(ui->actionNewProject_N);
        menu->addAction(ui->actionOpenProject_O);
        menu->exec(QCursor::pos());
        delete menu;
    }
}

//添加右侧项目菜单中的文件
static void addFolderItem(QTreeWidgetItem* parentItem,QString name,int itemType)
{
    QFileInfo fileInfo(name);
    QTreeWidgetItem* newItem=new QTreeWidgetItem(itemType);
    newItem->setText(0,fileInfo.fileName());
    newItem->setData(0,Qt::UserRole,QVariant(fileInfo.filePath()));
    parentItem->addChild(newItem);
}

//添加项目文件（头，源，其他）
void MainWindow::do_projectRightMenu_addFileSeries_triggered()
{
    (sender()==projectRightMenu->addHeader)?(addProjectFile(HEADER)):((sender()==projectRightMenu->addSource)?(addProjectFile(SOURCE)):(addProjectFile(OTHERS)));
}

void MainWindow::addProjectFile(int mode)
{
    //文件对话框
    QString fileName=QFileDialog::getOpenFileName(nullptr,(mode==HEADER)?("头文件"):((mode==SOURCE)?("源文件"):("其他文件")),QDir::currentPath(),(mode==HEADER)?("C/C++头文件(*.h *.hpp);;其他文件(*.*)"):((mode==SOURCE)?("C/C++源文件(*.c *.cpp *.cxx *.cc);;其他文件(*.*)"):("其他文件(*.*)")));
    if(fileName.isNull())return;

    //添加文件
    project->add(fileName,mode);//添加到项目记录中
    emit projectChanged(currentFilePath);//刷新
}

void MainWindow::do_fileChanged(QString newFilePath)
{
    if(currentFilePath.isNull()&&(!ui->plainTextEdit->toPlainText().isNull()))
        fileSaveAs();
    else
        fileSave(currentFilePath);

    currentFilePath=newFilePath;
    if(newFilePath.isNull())
        setNullEditor();
    else
        setEditor(newFilePath);
}

QString MainWindow::fileSaveAs()
{
    QString file;
    while((file=QFileDialog::getSaveFileName(nullptr,"另存为",QDir::currentPath(),"C/C++源文件(*.c *.cpp *.cxx *.C *.cc *.hpp *h);;其他文件(*.*)")).isNull())
        if(QMessageBox::warning(nullptr,"另存文件失败","是否重试？",QMessageBox::Yes|QMessageBox::Apply|QMessageBox::No)==QMessageBox::No)
            break;
    if(!file.isNull())
        fileSave(file);
    return file;
}

void MainWindow::fileSave(QString filePath)
{
    QFile file(filePath);
    file.open(QIODeviceBase::WriteOnly);
    file.write(ui->plainTextEdit->toPlainText().toUtf8());
    file.close();
}

void MainWindow::setNullEditor()
{
    //设置当前文件
    ui->plainTextEdit->clear();

    //设置文本编辑器，窗口标题
    ui->fileNameGroupBox->setTitle("File Name");
    this->setWindowTitle("Hello");
}

void MainWindow::setEditor(QString filePath)
{
    QFile newFile(filePath);
    QFileInfo newFileInfo(filePath);
    newFile.open(QIODeviceBase::ReadOnly);

    //设置当前文件
    ui->plainTextEdit->setPlainText(newFile.readAll());//设置文本编辑器内容，注意readAll()的返回值是QByteArray类型

    //设置文本编辑器，窗口标题
    ui->fileNameGroupBox->setTitle(newFileInfo.fileName());
    this->setWindowTitle(newFileInfo.absoluteFilePath());

    newFile.close();
}

void MainWindow::do_projectChanged(QString newProjectPath)
{
    //遍历添加项
    auto addFolderItems=[&](int mode)
    {
        project->query.prepare("select fileName from files where fileType=:type");
        project->query.bindValue(0,mode);
        project->query.exec();
        while(project->query.next())
            addFolderItem(projectDockWidget.treeProjectWidget->invisibleRootItem()->child(mode),project->query.record().value("fileName").toString(),FILEITEM);
    };

    //构建项目树
    auto buildProjectTree=[&]()
    {
        projectDockWidget.treeProjectWidget->setHeaderLabel(currentProjectPath);
        addFolderItem(projectDockWidget.treeProjectWidget->invisibleRootItem(),"头文件",TYPEITEM);
        addFolderItem(projectDockWidget.treeProjectWidget->invisibleRootItem(),"源文件",TYPEITEM);
        addFolderItem(projectDockWidget.treeProjectWidget->invisibleRootItem(),"其他文件",TYPEITEM);
        addFolderItems(HEADER);
        addFolderItems(SOURCE);
        addFolderItems(OTHERS);
    };

    //清理原项目树
    projectDockWidget.treeProjectWidget->clear();
    if(!currentProjectPath.isNull())
        delete project;

    //设置新项目树
    currentProjectPath=newProjectPath;
    if(!newProjectPath.isNull())
    {
        project=new Project(currentProjectPath);
        buildProjectTree();
    }
}

//“新建项目”槽
void MainWindow::do_Project_New_triggered()
{
    DialogNewProject* dialogNewProject=new DialogNewProject(this);
    while(dialogNewProject->exec()==QDialog::Accepted)
    {
        DialogNewProject::ProjectMessage message=dialogNewProject->inputMessage();
        if(message.projectName.isNull()||message.projectPath.isNull())
        {
            QMessageBox::warning(dialogNewProject,"警告","项目名称或项目路径为空");
            continue;
        }
        else
        {
            emit projectChanged(message.projectPath+'/'+message.projectName+".icpppro");
            break;
        }
    }
    delete dialogNewProject;
}

//“打开项目”槽
void MainWindow::do_Project_Open_triggered()
{
    QString projectName=QFileDialog::getOpenFileName(nullptr,"打开项目",QDir::currentPath(),"*.icpppro");
    if(!projectName.isNull())emit projectChanged(projectName);
}

void MainWindow::do_treeProjectWidget_currentItemChanged(QTreeWidgetItem* current,QTreeWidgetItem* previous)
{
    if(current==nullptr||current==previous)return;
    switch(current->type())
    {
    case FILEITEM:
        projectRightMenu->deleteFileMenu->setEnabled(true);
        emit fileChanged(current->data(0,Qt::UserRole).toString());
        break;
    case TYPEITEM:
        projectRightMenu->deleteFileMenu->setEnabled(false);
        break;
    }
}

void MainWindow::do_SettingsSeries_triggered()
{
    if(sender()==ui->actionSettingsFont_F)
    {
        bool ok=false;
        QFont font=QFontDialog::getFont(&ok);
        if(ok)
            ui->plainTextEdit->setFont(font);
    }
    else if(sender()==ui->actionSettingsColor_C)
    {
        DialogChooseColor* dialogChooseColor=new DialogChooseColor(this);
        if(dialogChooseColor->exec()==QDialog::Accepted)
        {
            //背景颜色
            char style[128];
            DialogChooseColor::RGB rgb=dialogChooseColor->inputMessage();
            sprintf(style,"background:rgb(%d,%d,%d);",rgb.r,rgb.g,rgb.b);

            //文字颜色
            if(rgb.r+rgb.g+rgb.b>300)strcat(style,"color:rgb(0,0,0);");
            else strcat(style,"color:rgb(255,255,255);");

            ui->plainTextEdit->setStyleSheet(style);
        }
        delete dialogChooseColor;
    }
}

void MainWindow::do_projectRightMenu_deleteFileSeries_triggered()
{
    enum{NOOPTION=0,DELETEFILE,REMOVEFILE};
    QFile file(projectDockWidget.treeProjectWidget->currentItem()->data(0,Qt::UserRole).toString());
    QFileInfo fileInfo(projectDockWidget.treeProjectWidget->currentItem()->data(0,Qt::UserRole).toString());
    auto deleteFileBox=[&](){return (QMessageBox::question(this,"删除","是否确定删除"+fileInfo.absoluteFilePath()+"？")==QMessageBox::Yes)?DELETEFILE:NOOPTION;};
    auto removeFileBox=[&](){return (QMessageBox::question(this,"从项目中移除","是否确定移除"+fileInfo.absoluteFilePath()+"？")==QMessageBox::Yes)?REMOVEFILE:NOOPTION;};

    if(int i=(sender()==projectRightMenu->deleteFile)?(deleteFileBox()):(removeFileBox()))
    {
        if(fileInfo.absoluteFilePath()==currentFilePath)
            emit fileChanged(QString());
        if(i==DELETEFILE)
            file.moveToTrash();
        project->del(fileInfo.absoluteFilePath(),projectDockWidget.treeProjectWidget->currentItem()->type());
        emit projectChanged(currentProjectPath);
    }
}

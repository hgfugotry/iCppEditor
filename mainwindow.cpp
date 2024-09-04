#include<iostream>
#include"ProjectRightMenu.hpp"
#include"dialognewproject.h"
#include"dialogchoosecolor.h"
#include"dialogsethowtocompile.h"
#include"mainwindow.h"
#include"ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{//MainWindow类:程序主窗口
    iniUi();
    iniConnects();
    this->setWindowTitle("iCppEditor");
}

void MainWindow::iniUi()
{//初始化界面
    ui->setupUi(this);

    //分配内存
    projectRightMenu=new ProjectRightMenu(this);
    tabWidget=new QTabWidget;

    //设置Tab可关闭,可移动
    tabWidget->setTabsClosable(true);
    tabWidget->setMovable(true);

    //设置布局,左侧为项目QDockWidget,中间和右侧为文本编辑器QTabWidget
    this->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea,projectDockWidget.dockWidget);
    ui->mainWindowLayout->addWidget(tabWidget);
}

void MainWindow::iniConnects()
{//初始化连接
    //连接菜单槽
    connect(ui->actionFileOpen_O,SIGNAL(triggered()),this,SLOT(do_File_Open_triggered()));//菜单栏->打开文件
    connect(ui->actionFileSave_S,SIGNAL(triggered()),this,SLOT(do_File_Save_triggered()));//菜单栏->保存文件
    connect(ui->actionFileSaveAs_A,SIGNAL(triggered()),this,SLOT(do_File_SaveAs_triggered()));//菜单栏->另存为文件
    connect(ui->actionBuildSettings_S,SIGNAL(triggered()),this,SLOT(do_Build_Settings_triggered()));//菜单栏->配置编译选项
    connect(ui->actionNewProject_N,SIGNAL(triggered()),this,SLOT(do_Project_New_triggered()));//菜单栏->新建项目
    connect(ui->actionOpenProject_O,SIGNAL(triggered()),this,SLOT(do_Project_Open_triggered()));//菜单栏->打开项目
    connect(ui->actionSettingsFont_F,SIGNAL(triggered()),this,SLOT(do_SettingsSeries_triggered()));//菜单栏->设置字体
    connect(ui->actionSettingsColor_C,SIGNAL(triggered()),this,SLOT(do_SettingsSeries_triggered()));//菜单栏->设置颜色

    connect(tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(do_tabWidget_tabCloseRequested(int)));//Tab栏关闭某一文本编辑器

    //连接与左侧项目QDockWidget有关的槽
    //连接显示项目右键菜单的槽
    connect(projectDockWidget.treeProjectWidget,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(do_treeProjectWidget_customContextMenuRequested(const QPoint&)));
    //项目右键菜单
    connect(projectRightMenu->addHeader,SIGNAL(triggered()),this,SLOT(do_projectRightMenu_addFileSeries_triggered()));
    connect(projectRightMenu->addSource,SIGNAL(triggered()),this,SLOT(do_projectRightMenu_addFileSeries_triggered()));
    connect(projectRightMenu->addOthers,SIGNAL(triggered()),this,SLOT(do_projectRightMenu_addFileSeries_triggered()));
    connect(projectRightMenu->deleteFile,SIGNAL(triggered()),this,SLOT(do_projectRightMenu_deleteFileSeries_triggered()));
    connect(projectRightMenu->removeFile,SIGNAL(triggered()),this,SLOT(do_projectRightMenu_deleteFileSeries_triggered()));
    //其他
    connect(this,SIGNAL(projectChanged(QString)),this,SLOT(do_projectChanged(QString)));//打开的项目发生改变
    connect(projectDockWidget.treeProjectWidget,SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)),this,SLOT(do_treeProjectWidget_currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)));//项目树菜单中所选项发生改变
}

MainWindow::~MainWindow()
{
    delete ui;
    delete projectRightMenu;
    delete tabWidget;
}

MainWindow::ProjectDockWidget::ProjectDockWidget(QWidget* parent)
{//ProjectDockWidget类:程序左侧项目DockWidget
    //分配内存
    dockWidget=new QDockWidget(parent);
    dockWidgetContext=new QWidget;
    treeProjectWidget=new QTreeWidget(dockWidgetContext);
    vBoxLayout=new QVBoxLayout;

    //项目树
    treeProjectWidget->setStyleSheet("background:rgb(255,245,255);");
    treeProjectWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    //布局
    vBoxLayout->addWidget(treeProjectWidget);

    //容器
    dockWidgetContext->setLayout(vBoxLayout);

    //窗口
    dockWidget->setFeatures(QDockWidget::DockWidgetFeatures(0x6));
    dockWidget->setAllowedAreas(Qt::DockWidgetArea::AllDockWidgetAreas);
    dockWidget->setWindowTitle("项目");
    dockWidget->setWidget(dockWidgetContext);
}

MainWindow::ProjectDockWidget::~ProjectDockWidget()
{
    delete vBoxLayout;
    delete treeProjectWidget;
    delete dockWidgetContext;
    delete dockWidget;
}

void MainWindow::do_File_Open_triggered()
{//菜单栏打开文件槽
    //打开文件选择对话框
    QString fileName=QFileDialog::getOpenFileName(nullptr,"打开文件",QDir::currentPath(),"C源文件(*.c *.h);;C++源文件(*.cpp *.cxx *.cc *.hpp *.h);;其他文件(*.*)");
    if(!fileName.isNull())setEditor(fileName);
}

void MainWindow::do_File_Save_triggered()
{//菜单栏保存文件槽
    fileSave(tabPlainTextEditWidgets[tabWidget->currentIndex()]->fileName);
    deleteCurrentStar();
}

void MainWindow::do_File_SaveAs_triggered()
{//菜单栏另存为槽
    fileSaveAs();
}

void MainWindow::do_treeProjectWidget_customContextMenuRequested(const QPoint& pos)
{//显示项目右键菜单
    Q_UNUSED(pos);
    if(!currentProjectPath.isNull())
        projectRightMenu->exec(QCursor::pos());//项目右键菜单
    else
    {//新建或打开项目菜单
        QMenu* menu=new QMenu(this);
        menu->addAction(ui->actionNewProject_N);
        menu->addAction(ui->actionOpenProject_O);
        menu->exec(QCursor::pos());
        delete menu;
    }
}

void MainWindow::addFolderItem(QTreeWidgetItem* parentItem,QString name,int itemType)
{//添加左侧项目菜单中的文件或目录
    //创建新项
    QTreeWidgetItem* newItem=new QTreeWidgetItem(itemType);

    if(itemType==FILEITEM)
    {
        //设置文件路径
        QFileInfo fileInfo(name);
        setFileItem(newItem,fileInfo.fileName(),fileInfo.absoluteFilePath());
    }
    else
        newItem->setText(0,name);
    //连接子项
    parentItem->addChild(newItem);
}

void MainWindow::setFileItem(QTreeWidgetItem* fileItem,QString name,QString absPathName)
{//设置项目菜单文件项的数据
    fileItem->setText(0,name);
    fileItem->setData(0,Qt::UserRole,QVariant(absPathName));
}

void MainWindow::do_projectRightMenu_addFileSeries_triggered()
{//添加项目文件（头，源，其他）
    (sender()==projectRightMenu->addHeader)?(addProjectFile(HEADER)):((sender()==projectRightMenu->addSource)?(addProjectFile(SOURCE)):(addProjectFile(OTHERS)));
}

void MainWindow::addProjectFile(int mode)
{
    //文件对话框
    QString fileName=QFileDialog::getOpenFileName(nullptr,(mode==HEADER)?("头文件"):((mode==SOURCE)?("源文件"):("其他文件")),QDir::currentPath(),(mode==HEADER)?("C/C++头文件(*.h *.hpp);;其他文件(*.*)"):((mode==SOURCE)?("C/C++源文件(*.c *.cpp *.cxx *.cc);;其他文件(*.*)"):("其他文件(*.*)")));
    if(fileName.isNull())return;

    //添加文件
    project->add(fileName,mode);//添加到项目记录中
    emit projectChanged(currentProjectPath);//刷新
}

QString MainWindow::fileSaveAs()
{//另存文件,返回另存文件名,若取消,则返回使QString::isNull()为真的QString对象
    QString file;
    while((file=QFileDialog::getSaveFileName(nullptr,"另存为",QDir::currentPath(),"C/C++源文件(*.c *.cpp *.cxx *.C *.cc *.hpp *h);;其他文件(*.*)")).isNull())
        if(QMessageBox::warning(nullptr,"另存文件失败","是否重试？",QMessageBox::Yes|QMessageBox::Apply|QMessageBox::No)==QMessageBox::No)
            break;
    if(!file.isNull())
        fileSave(file);
    return file;
}

void MainWindow::fileSave(QString fileName)
{//保存当前plainTextEdit的文件到fileName指定的文件中
    QFile file(fileName);
    file.open(QIODeviceBase::WriteOnly);
    file.write(tabPlainTextEditWidgets[tabWidget->currentIndex()]->plainTextEdit->toPlainText().toUtf8());
    file.close();
}

void MainWindow::deleteCurrentStar()
{//删除当前打开的文件表示文件以修改的末尾的*
    int index=tabWidget->currentIndex();
    QString tabText=tabWidget->tabText(index);
    tabText.erase(tabText.cend()-1);
    tabWidget->setTabText(index,tabText);
    tabPlainTextEditWidgets[index]->loaded=false;
}

void MainWindow::setEditor(QString filePath)
{//载入新打开的文件
    //创建新TabWidget
    newTabWidgetWithPlainTextEdit(filePath);

    //获取文件信息
    QFile newFile(filePath);
    QFileInfo newFileInfo(filePath);
    newFile.open(QIODeviceBase::ReadOnly);

    //载入文本编辑器
    (*(tabPlainTextEditWidgets.end()-1))->plainTextEdit->setPlainText(newFile.readAll());//设置文本编辑器内容，注意readAll()的返回值是QByteArray类型

    //设置文本编辑器标题
    (*(tabPlainTextEditWidgets.end()-1))->tab->setWindowTitle(newFileInfo.fileName());

    //关闭文件
    newFile.close();
}

void MainWindow::do_projectChanged(QString newProjectPath)
{//项目改变槽
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

void MainWindow::do_Project_New_triggered()
{//“新建项目”槽
    DialogNewProject* dialogNewProject=new DialogNewProject(this);
    while(dialogNewProject->exec()==QDialog::Accepted)
    {
        DialogNewProject::ProjectMessage message=dialogNewProject->inputMessage();
        if(message.projectName.size()<3||message.projectPath.size()<3)
        {
            QMessageBox::warning(dialogNewProject,"警告","项目名称或项目路径过短或为空");
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

void MainWindow::do_Project_Open_triggered()
{//“打开项目”槽
    QString projectName=QFileDialog::getOpenFileName(nullptr,"打开项目",QDir::currentPath(),"*.icpppro");
    if(!projectName.isNull())emit projectChanged(projectName);
}

void MainWindow::do_treeProjectWidget_currentItemChanged(QTreeWidgetItem* current,QTreeWidgetItem* previous)
{//项目菜单选中向改变处理槽
    if(current==nullptr||current==previous)return;
    switch(current->type())
    {
    case FILEITEM:
        projectRightMenu->deleteFileMenu->setEnabled(true);
        setEditor(current->data(0,Qt::UserRole).toString());
        break;
    case TYPEITEM:
        projectRightMenu->deleteFileMenu->setEnabled(false);
        break;
    }
}

void MainWindow::do_SettingsSeries_triggered()
{//设置处理槽
    if(sender()==ui->actionSettingsFont_F)
        setEditorFont();
    else if(sender()==ui->actionSettingsColor_C)
        setEditorColor();
}

void MainWindow::setEditorFont()
{//更改当前文本编辑器字体
    if(reportIfHasNotAnyFileOpen())return;
    bool ok=false;
    QFont font=QFontDialog::getFont(&ok);
    if(ok)
        tabPlainTextEditWidgets[tabWidget->currentIndex()]->plainTextEdit->setFont(font);
}

void MainWindow::setEditorColor()
{//更改当前文本编辑器颜色
    if(reportIfHasNotAnyFileOpen())return;
    DialogChooseColor* dialogChooseColor=new DialogChooseColor(this);
    if(dialogChooseColor->exec()==QDialog::Accepted)
    {
        //背景颜色
        char style[128];
        DialogChooseColor::RGB rgb=dialogChooseColor->inputMessage();
        sprintf(style,"background:rgb(%d,%d,%d);",rgb.r,rgb.g,rgb.b);

        //文字颜色
        if(rgb.r+rgb.g+rgb.b>300)strncat(style,"color:rgb(0,0,0);",100);
        else strncat(style,"color:rgb(255,255,255);",100);

        //更改颜色
        tabPlainTextEditWidgets[tabWidget->currentIndex()]->plainTextEdit->setStyleSheet(style);
    }
    delete dialogChooseColor;
}

bool MainWindow::reportIfHasNotAnyFileOpen()
{
    if(tabPlainTextEditWidgets.size()==0)
    {
        QMessageBox::information(this,"提示","未打开文件");
        return true;
    }
    return false;
}

void MainWindow::do_projectRightMenu_deleteFileSeries_triggered()
{//项目中删除或移除文件槽
    enum{NOOPTION=0,DELETEFILE,REMOVEFILE};
    QFile file(projectDockWidget.treeProjectWidget->currentItem()->data(0,Qt::UserRole).toString());
    QFileInfo fileInfo(projectDockWidget.treeProjectWidget->currentItem()->data(0,Qt::UserRole).toString());
    auto deleteFileBox=[&](){return (QMessageBox::question(this,"删除","是否确定删除"+fileInfo.absoluteFilePath()+"？")==QMessageBox::Yes)?DELETEFILE:NOOPTION;};
    auto removeFileBox=[&](){return (QMessageBox::question(this,"从项目中移除","是否确定移除"+fileInfo.absoluteFilePath()+"？")==QMessageBox::Yes)?REMOVEFILE:NOOPTION;};

    if(int i=(sender()==projectRightMenu->deleteFile)?(deleteFileBox()):(removeFileBox()))
    {
        //若在文本编辑器中打开则关闭文本编辑器
        if(int index=seekTabFile(fileInfo.absoluteFilePath())!=-1)
            delTabWidgetWithPlainTextEdit(index);
        if(i==DELETEFILE)
            file.moveToTrash();//移动到回收站
        //从项目中移除
        project->del(fileInfo.absoluteFilePath(),projectDockWidget.treeProjectWidget->currentItem()->type());
        emit projectChanged(currentProjectPath);
    }
}

void MainWindow::do_Build_Settings_triggered()
{//"配置编译选项"槽
    DialogSetHowToCompile* dialogSetHowToCompile=new DialogSetHowToCompile(this);
    dialogSetHowToCompile->exec();
    delete dialogSetHowToCompile;
}

void MainWindow::newTabWidgetWithPlainTextEdit(QString fileName)
{//创建新文本编辑器
    tabPlainTextEditWidgets.push_back(new TabPlainTextEditWidget(fileName));
    this->tabWidget->addTab((*(tabPlainTextEditWidgets.end()-1))->tab,fileName);
    QFileInfo fileInfo(fileName);
    this->tabWidget->setTabText(tabPlainTextEditWidgets.size()-1,fileInfo.fileName());
    connect((*(tabPlainTextEditWidgets.end()-1))->plainTextEdit,SIGNAL(textChanged()),this,SLOT(do_plainTextEdits_textChanged()));
}

void MainWindow::delTabWidgetWithPlainTextEdit(QString fileName)
{//删除指定文件的编辑器
    int i=seekTabFile(fileName);
    if(i!=-1)
        delTabWidgetWithPlainTextEdit(i);
}

void MainWindow::delTabWidgetWithPlainTextEdit(int index)
{//删除指定索引的编辑器
    tabWidget->removeTab(index);
    delete tabPlainTextEditWidgets[index];
    tabPlainTextEditWidgets.erase(tabPlainTextEditWidgets.begin()+index);
}

int MainWindow::seekTabFile(QString fileName)
{//查找指定文件路径的文本编辑器索引,未找到返回-1
    for(size_t index=0;index<tabPlainTextEditWidgets.size();++index)
        if(tabPlainTextEditWidgets[index]->fileName==fileName)
            return index;
    return -1;
}

MainWindow::TabPlainTextEditWidget::TabPlainTextEditWidget(QString fileName_)
{//TabPlainTextEditWidget类:单个文本编辑器
    fileName=fileName_;
    tab=new QWidget;
    plainTextEdit=new QPlainTextEdit;
    vBoxLayout=new QVBoxLayout;
    vBoxLayout->addWidget(plainTextEdit);
    tab->setLayout(vBoxLayout);
}

MainWindow::TabPlainTextEditWidget::~TabPlainTextEditWidget()
{
    delete plainTextEdit;
    delete vBoxLayout;
    delete tab;
}

void MainWindow::do_tabWidget_tabCloseRequested(int index)
{//关闭单个文本编辑器槽
    if((*(tabWidget->tabText(index).toStdString().end()-1))=='*')
    {
        int i=QMessageBox::warning(this,"文件未保存","文件未保存,是否保存?",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
        if(i==QMessageBox::Yes)fileSave(tabWidget->tabText(index));
        else if(i==QMessageBox::Cancel)return;
    }
    delTabWidgetWithPlainTextEdit(index);
}

void MainWindow::do_plainTextEdits_textChanged()
{//文本编辑器文本改变槽,在文本编辑器标题后添加*,忽略首次加载文件
    int currentIndex=tabWidget->currentIndex();
    if(tabPlainTextEditWidgets[currentIndex]->loaded==false)
    {
        tabPlainTextEditWidgets[currentIndex]->loaded=true;
        return;
    }
    QFileInfo fileInfo(tabPlainTextEditWidgets[currentIndex]->fileName);
    if((*(tabWidget->tabText(currentIndex).toStdString().end()-1))!='*')
        tabWidget->setTabText(currentIndex,fileInfo.fileName()+'*');
}

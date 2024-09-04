#include "project.h"

#include<iostream>

Project::Project(QString path)
{
    dataBase=QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName(path);
    if(!dataBase.open())std::cout<<"dataBase.open() error."<<std::endl;
    query=QSqlQuery(dataBase);
    if(!query.exec("create table if not exists files(id INTEGER PRIMARY KEY AUTOINCREMENT,path TEXT NOT NULL,name TEXT NOT NULL,type INTEGER NOT NULL);"))std::cout<<"Create table error."<<std::endl;
    if(!query.exec("create table if not exists compilerSettings(compiler,flags,output);"))std::cout<<"Create table error."<<std::endl;
}

void Project::add(QString filePath,int type)
{
    QString sql=QString("insert into files(path,name,type) values('%1',%2);").arg(filePath).arg(type);
    if(!query.exec(sql))std::cout<<"Insert values error."<<std::endl;
}

void Project::del(QString filePath,int type)
{
    QString sql=QString("delete from files where fileName='%1' and fileType=%2;").arg(filePath).arg(type);
    if(!query.exec(sql))std::cout<<"Insert values error."<<std::endl;
}

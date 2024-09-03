#ifndef PROJECT_H
#define PROJECT_H

#include<QString>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlRecord>

class Project
{
public:
    QSqlDatabase dataBase;
    QSqlQuery query;
public:
    enum fileType{HEADER,SOURCE,OTHERS};
    Project(QString path);
    Project(){}
    void add(QString filePath,int type);
    void del(QString filePath,int type);
};

#endif // PROJECT_H

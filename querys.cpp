#include "querys.h"
#include "ui_querys.h"
#include<QMessageBox>
#include<QTableView>
querys::querys(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::querys)
{
    ui->setupUi(this);
    //创建及打开数据库
    CreateDatebaseFunc();
    //创建数据表
    CreateTableFunc();
    //显示全部数据
    ShowAll();
}

querys::~querys()
{
    delete ui;
}
void querys::CreateDatebaseFunc()
{
    //1:添加数据库驱动
    sqldb = QSqlDatabase::addDatabase("QSQLITE");
    //2:设置数据库名称
    sqldb.setDatabaseName("my.db");
    //3:判断是否打开成功
    sqldb.open();
    if(sqldb.open() == true)
    {
        QMessageBox::information(0,"正确","数据打开成功",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(0,"错误","打开失败",QMessageBox::Ok);
    }
}
void querys::CreateTableFunc()
{
    QSqlQuery createquery;
    //创建sql语句 '1990-01-01','09;30'
    QString strsql = QString("create table if not exists flight("
                             "id int primary key not null,"
                             "src text not null,"
                             "des text not null,"
                             "date date not null,"
                             "start_time time not null,"
                             "end_time time not null,"
                             "price int not null,"
                             "discount int not null,"
                             "rest int not null,"
                             "comp text not null"
                              ");");
    //执行sql语句
    if(createquery.exec(strsql) == false)
    {
        QMessageBox::critical(0,"失败","数据表创建失败",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(0,"成功","创建成功",QMessageBox::Ok);

    }
}
void querys::ShowAll()
{
    QString strsql = QString("select * from flight");
  //  QMessageBox::information(0,"成功","显示全部结果",QMessageBox::Ok);
    QSqlQuery query(strsql);
    QSqlQueryModel *sqlmodel = new QSqlQueryModel();//存储结果集
    sqlmodel->setQuery(query);
    ui->tableView->setModel(sqlmodel);
    ui->tableView->show();
}
void querys::on_pushButton_Search_clicked()
{
    QString ID = ui->lineEdit_ID->text();
    QString strsql = QString("select * from flight where id="+ID);
    QSqlQuery query(strsql);
    QSqlQueryModel *sqlmodel = new QSqlQueryModel();//存储结果集
    sqlmodel->setQuery(query);
    ui->tableView->setModel(sqlmodel);
    ui->tableView->show();
}


#include "options.h"
#include "ui_options.h"
#include<QMessageBox>
#include<QDate>
#include<QDebug>
options::options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::options)
{
    ui->setupUi(this);
    //创建及打开数据库
   CreateDatebaseFunc();
    //创建数据表
    CreateTableFunc();
    //显示全部数据
    ShowAll();
}
void options::CreateDatebaseFunc()
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
void options::CreateTableFunc()
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
void options::ShowAll()
{
    QString strsql = QString("select * from flight");
  //  QMessageBox::information(0,"成功","显示全部结果",QMessageBox::Ok);
    QSqlQuery query(strsql);
    QSqlQueryModel *sqlmodel = new QSqlQueryModel();//存储结果集
    sqlmodel->setQuery(query);
    ui->tableView->setModel(sqlmodel);
    ui->tableView->show();
}

options::~options()
{
    delete ui;
}

void options::on_pushButton_Search_clicked()
{
    QString ID = ui->lineEdit_ID->text();
    QString strsql = QString("select * from flight where id="+ID);
    QSqlQuery query(strsql);
    QSqlQueryModel *sqlmodel = new QSqlQueryModel();//存储结果集
    sqlmodel->setQuery(query);
    ui->tableView->setModel(sqlmodel);
    ui->tableView->show();
}


void options::on_pushButton_Insert_clicked()
{
    int ID = ui->lineEdit_ID->text().toInt();
    QString src = ui->lineEdit_src->text();
    QString des = ui->lineEdit_des->text();
    QString date = ui->dateEdit->date().toString();
    QString start_time =ui->timeEdit_start->time().toString();
    QString end_time=ui->timeEdit_end->time().toString();
    int price=ui->lineEdit_price->text().toInt();
    int discount=ui->lineEdit_discount->text().toInt();
    int rest = ui->lineEdit_rest->text().toInt();
    QString comp = ui->lineEdit_comp->text();

    QString str = QString("insert into flight "
                         "values(%1,'%2','%3','%4','%5','%6',%7,%8,%9,'%10')").arg(ID).arg(src).arg(des).arg(date).arg(start_time).arg(end_time).arg(price).arg(discount).arg(rest).arg(comp);
    QSqlQuery QSqlQuery;
    if(QSqlQuery.exec(str) == false)
    {
        QMessageBox::critical(0,"失败","数据插入失败",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(0,"成功","插入成功",QMessageBox::Ok);
    }
    ShowAll();
}


void options::on_pushButton_Del_clicked()
{
    QString ID = ui->lineEdit_ID->text();
    QString strsql = QString("delete from flight where id="+ID);
    QSqlQuery QSqlQuery;
    if(QSqlQuery.exec(strsql) == false)
    {
        QMessageBox::critical(0,"失败","数据删除失败",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(0,"成功","删除成功",QMessageBox::Ok);
    }
    ShowAll();
}


void options::on_pushButton_Update_clicked()
{
    int ID = ui->lineEdit_ID->text().toInt();
    QString src = ui->lineEdit_src->text();
    QString des = ui->lineEdit_des->text();
    QString date = ui->dateEdit->date().toString();
    QString start_time =ui->timeEdit_start->time().toString();
    QString end_time=ui->timeEdit_end->time().toString();
    QString comp = ui->lineEdit_comp->text();
    QString str="update flight set ";
    if(!src.isEmpty()) str = str+QString("src='%1',").arg(src);
    if(!des.isEmpty()) str = str+QString("des='%1',").arg(des);
    if(!date.isEmpty()) str = str+QString("date='%1',").arg(date);
    if(!start_time.isEmpty()) str = str+QString("start_time='%1',").arg(start_time);
    if(!end_time.isEmpty()) str = str+QString("end_time='%1',").arg(end_time);
    if(!ui->lineEdit_price->text().isEmpty())
    {
        int price=ui->lineEdit_price->text().toInt();
        str = str+QString("price=%1,").arg(price);
    }
    if(!ui->lineEdit_discount->text().isEmpty())
    {
         int discount=ui->lineEdit_discount->text().toInt();
        str = str+QString("discount=%1,").arg(discount);
    }
    if(!ui->lineEdit_rest->text().isEmpty())
    {
         int rest = ui->lineEdit_rest->text().toInt();
        str = str+QString("rest=%1,").arg(rest);
    }
    if(!comp.isEmpty()) str = str+QString("comp='%1',").arg(comp);
    str.chop(1);
    str = str +QString("where id=%1").arg(ID);
    qDebug()<<"str="<<str;

    QSqlQuery QSqlQuery;
    if(QSqlQuery.exec(str) == false)
    {
        QMessageBox::critical(0,"失败","数据更新失败",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(0,"成功","更新成功",QMessageBox::Ok);
    }
    ShowAll();
}


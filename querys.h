#ifndef QUERYS_H
#define QUERYS_H

#include <QWidget>
#include<QSqlDatabase>//连接，创建数据库
#include<QSqlQuery>//专用于DML（数据操作）
#include<QSqlQueryModel>//查询模型
#include<QSqlError>
namespace Ui {
class querys;
}

class querys : public QWidget
{
    Q_OBJECT

public:
    explicit querys(QWidget *parent = nullptr);
    ~querys();

private slots:
    void on_pushButton_Search_clicked();

private:
    Ui::querys *ui;
    void CreateDatebaseFunc();
    void CreateTableFunc();
    void ShowAll();
    QSqlDatabase sqldb;//创建Qt和数据库链接

};

#endif // QUERYS_H

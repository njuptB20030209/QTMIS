#ifndef OPTIONS_H
#define OPTIONS_H

#include <QWidget>
#include<QSqlDatabase>//连接，创建数据库
#include<QSqlQuery>//专用于DML（数据操作）
#include<QSqlQueryModel>//查询模型
#include<QSqlError>
namespace Ui {
class options;
}

class options : public QWidget
{
    Q_OBJECT

public:
    explicit options(QWidget *parent = nullptr);
    ~options();

private slots:
    void on_pushButton_Search_clicked();

    void on_pushButton_Insert_clicked();

    void on_pushButton_Del_clicked();

    void on_pushButton_Update_clicked();

private:
    Ui::options *ui;
    void CreateDatebaseFunc();
    void CreateTableFunc();
    void ShowAll();
    QSqlDatabase sqldb;//创建Qt和数据库链接
};

#endif // OPTIONS_H

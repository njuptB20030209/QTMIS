#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_push_clicked()
{
    //发送信号给主窗口
    QString userName = ui->userName->text();
    QString passwd = ui->passwd->text();
    if(userName=="B20030209")
    {
        if(passwd=="123456")
        {
            emit mysigal2();
            this->hide();
        }
        else
        {
             QMessageBox::information(this,"Wrong","wrong passwd");
        }
    }
    else
    {
        QMessageBox::information(this,"Wrong","wrong username");
    }

}


void login::on_cancel_clicked()
{
    emit mysigal();
    this->hide();
}


#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&log,&login::mysigal,this,&Widget::show);
    connect(&log,&login::mysigal2,this,&Widget::generate);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::generate()
{
    opt = new options;
    opt->show();
}
void Widget::on_manage_clicked()
{
    this->hide();
    log.show();
}


void Widget::on_query_clicked()
{
    this->hide();
    qy = new querys;
    qy->show();
}


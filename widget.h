#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"login.h"
#include"ui_login.h"
#include"options.h"
#include"querys.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_manage_clicked();
    void on_query_clicked();
    void generate();
private:
    Ui::Widget *ui;
    login log;
    options *opt;
    querys *qy;
};
#endif // WIDGET_H

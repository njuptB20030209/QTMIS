#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
signals:
    void mysigal();
    void mysigal2();
private slots:
    void on_push_clicked();

    void on_cancel_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H

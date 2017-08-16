#include "logindialog.h"
#include "ui_logindialog.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <string>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    //ui->password->setVisible(false);
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}


void LoginDialog::on_loginButton_clicked()
{
    QString qusername = ui->username->text();
    std::string username = qusername.toStdString();
    if(username == " ") {
        QMessageBox::information(NULL, "错误", "请输入用户名！");
    }
    else {
        MainWindow *m = new MainWindow(username);
        m->show();
        this->close();
    }

}

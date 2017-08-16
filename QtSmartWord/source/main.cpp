#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog lg;
    lg.show();
    return a.exec();
}

//有道api http://fanyi.youdao.com/openapi.do?keyfrom=QTSmartWord&key=1708560784&type=data&doctype=text&version=1.0&q=我很聪明

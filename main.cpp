#include "mainwindow.h"
#include <QTextCodec> // подключение класса кодека текста
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.show();
    return a.exec();
}

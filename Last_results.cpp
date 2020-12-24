#include "Last_results.h"
#include <QMessageBox>

bookFile::bookFile()  // конструктор
{
    f=new QFile("book.txt");// создание объект-файл
    f->open(QFile::ReadWrite); // открытие файла
    // для ввода-вывода
 }
bookFile::~bookFile()   // деструктор
{
    f->close();
    delete f;
}
bool bookFile::addRec(recType r)
{
    f->seek(f->size()); // переход на конец файла
    QDataStream out(f); // связь с файлом поток вывода
    out<<r.current_date<<r.size<<r.matrix<<r.results;// вывод данных в файл
    return true;
}
bool bookFile::readRec()
{
    QDataStream in(f); // связь с файлом поток ввода
    if (in.atEnd())return false;
    else
    {
        in>>r.current_date>>r.size>>r.matrix>>r.results;
        return true;
    }
}

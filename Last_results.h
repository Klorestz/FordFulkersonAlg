#ifndef BOOKFILE_H
#define BOOKFILE_H
#include <QFile>

struct recType   // структура записи для одного абонента
{	QString size="",matrix="",results="",current_date="";   };

class bookFile
{
public:
    QFile * f;    // указатель на объект класса QFile
    recType r;  // буфер ввода-вывода
    bookFile();  // конструктор
    ~bookFile(); // деструктор
    bool addRec(recType r); // добавление записи в файл
    bool readRec();	    // чтение записи из файда
};

#endif // BOOKFILE_H

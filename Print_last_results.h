#ifndef PRINTFORM_H
#define PRINTFORM_H
#include "Last_results.h"
#include <QTableWidget>
#include <QPushButton>

class printForm : public QWidget
{
    QTableWidget *table;  // таблица
    QPushButton *btnExit;
    void showRow(int i,recType r);// вывод строки таблицы
public:
    printForm();    // конструктор
    void showAll(); // показать все записи
    void showResults(recType r1); // показать результаты поиска
};

#endif // PRINTFORM_H

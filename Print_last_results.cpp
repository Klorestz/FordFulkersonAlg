#include "Print_last_results.h"
#include <QHBoxLayout>
#include <QMessageBox>
#include <QHeaderView>
#include <QFlag>
printForm::printForm()
{
    QColor c=QColor(Qt::gray).lighter(155);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window,c);
    this->setPalette(palette);
     this->setWindowTitle("Результат");
     QStringList strlist; // объект Список строк
     strlist << "Дата вычисления" << "Размер матрицы"<< "Исходная матрица"
             << "Максимальный поток"; // записываем строки заголовка
     table = new QTableWidget(10000,4,this); // создаем таблицу
     table->setHorizontalHeaderLabels(strlist);                                                                                               //  заголовок
     QHBoxLayout *layoutG2 = new QHBoxLayout();
    btnExit=new QPushButton("Назад", this);
    layoutG2->addSpacing(300);
    layoutG2->addWidget(btnExit);
    layoutG2->addSpacing(300);
    QVBoxLayout *layout_main = new QVBoxLayout(this);
    layout_main->addWidget(table);
    layout_main->addLayout(layoutG2);
     connect(btnExit, SIGNAL(clicked(bool)),
             this,SLOT(close()));
}
void printForm::showRow(int i,recType r)
{
   QTableWidgetItem *item; // элемент таблицы
   item = new QTableWidgetItem(); // создание элемент
   item->setFlags(Qt::ItemIsEnabled);//запрет на изменение
   item->setText(r.current_date);   // записывание текст
   table->setItem(i,0,item);// привязывание элемент

   item = new QTableWidgetItem(); // создание элемент
   item->setFlags(Qt::ItemIsEnabled);//запрет на изменение
   item->setText(r.size);   // записывание текст
   table->setItem(i,1,item);// привязывание элемент

    item = new QTableWidgetItem();// создание элемент
    item->setFlags(Qt::ItemIsEnabled);//запрет на изменение
    item->setText(r.matrix);// записывание текст
    table->setItem(i,2,item); // привязывание элемент

    item = new QTableWidgetItem();// создание элемент
    item->setFlags(Qt::ItemIsEnabled);//запрет на изменение
    item->setText(r.results); // записывание текст
    table->setItem(i,3,item); // привязывание элемент
}
void printForm::showAll()
{
    bookFile book;
    if (!book.readRec())
    {    // если файл пустой , то создаем сообщение
        QMessageBox msg(QMessageBox::Critical,
                "Нет данных",
                "База пуста",
                QMessageBox::Ok,0);
        msg.exec(); // вывод сообщения
    }
    else
     {   // иначе - выводим таблицу по строкам
         showRow(0,book.r);
        int i=0;
        while (book.readRec())
           showRow(++i,book.r);
        show();
        table->setRowCount(i+2);
        recType r;
        showRow(i+1,r);
        table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        resize(750,430);
     }
}

#include "Information.h"
//#include <QVBoxLayout>
#include <QHBoxLayout>
Spravka::Spravka(QWidget *parent)
    : QMainWindow(parent)
{
    QColor c=QColor(Qt::gray).lighter(155);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window,c);
    this->setPalette(palette);
    QString information = "Назначение программы является поиск максимального потока в транспортной сети.\n\nДля успешной активации Вам нужно:\n- Изменить размер матрицы (Если это необходимо);\n- Заполнить матрицу смежности в главном меню (Значения ячеек матрицы должны быть больше 0).\n\nРезультатом работы программы является:\n- Значение максимального потока в заданной сети;\n- Вершины, которые являются источником и стоком;\n- Матрица потока, полученная в результате вычисления.\n\nПосле удачного поиска результат будет сохранен и его можно будет увидеть, нажав на кнопку 'Последние вычисления'. ";
   //Создание главного виджета
   QWidget *mainWidget = new QWidget;
    QLabel *inform_text = new QLabel;//Создание переменной для вывода текста
    btnExit = new QPushButton("Назад",this);
    //Название окна
    this->setWindowTitle("О программе...");
    //Создание виджетов для компоновки
    inform_text->setText(information);
    QHBoxLayout *layout2 = new QHBoxLayout();
    QVBoxLayout *layout_main = new QVBoxLayout(this);
    layout2->addSpacing(300);
    layout2->addWidget(btnExit);
    layout2->addSpacing(300);
    layout_main->addWidget(inform_text);
    layout_main->addLayout(layout2);
    mainWidget->setLayout(layout_main);
    setCentralWidget(mainWidget);
    connect(btnExit, SIGNAL(clicked(bool)),
             this,SLOT(close()));
    resize(300,200);// Изменени размера окна
}

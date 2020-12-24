#ifndef mainForm_h
#define mainForm_h
#include <QWidget>
#include <QPushButton>
#include <QTextCodec>
#include <QTableWidget>
#include <QMenu>
#include <QMenuBar>
#include <QMainWindow>
#include <QLabel>
#include <QMessageBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QApplication>
#include <QBEInteger>
#include <QDate>
#include <QGridLayout>
#include "Last_results.h"
#include "Print_last_results.h"
#include "Information.h"
#include "Output_result.h"
class Window : public QMainWindow
{
    //Объявление виджетов интерфейса
    Q_OBJECT
    QLabel *size_matrix, *text_size;//Переменные для пояснительного текста
    QLineEdit *input_size;//Поле для изменение размера матрицы
    QTableWidgetItem *item;//Ячейка матрицы
    QMenuBar *menu_file, *menu_inform;//Меню приложения
    QPushButton * btnPrint, * btnChange,* btnCalc;//Кнопки для выполнения различных функций
    QTableWidget * tableMatrix;//Матрица для ввода значений
    Spravka winSpravka; //Справочная форма
    printForm winPrint;//Форма, показывающая последние вычисления
    Output_result winResult;//Форма, показывающая результат вычисления
public:
    //Объявление переменных, предназаченных для вычислений
    QStringList name_table;//Переменная для изменения заголовков таблицы
    QString Label1,Label2,resultstr;//Переменные для работы со строками
    int j,i,n=5;//Переменны для работы с матрицей
    int matrix_algoritm[100][100];//Матрица, которая будет передана в функцию для вычисления максимального потока
    int immutable_matrix[100][100];//Матрица в неизменном виде
    int matrix_flow[100][100];//Матрица потока
    //Конструктор
    Window(QWidget *parent=0);
public slots:
    void showInform();   // показать справочную форму
    void ChangeSize(); // функция изменения размеров матрицы
    void showCalc();  // показать форму с результатом вычисления
    void showPrint(); //показать форму последних вычислений
    void addLastResults();
};

#endif

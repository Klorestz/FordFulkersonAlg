#include "CurSource_CurStock.h"
#include "AlgoritmFordFalkerson.h"
#include "Output_message.h"
#include "mainwindow.h"
Window::Window(QWidget *parent)
    : QMainWindow(parent)
{
    QColor c=QColor(Qt::gray).lighter(155);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window,c);
    this->setPalette(palette);
    // Графическое изображение для кнопок в меню
    QPixmap quitpix("quit.png");
    QPixmap spravkapix("spravka.png");
    // Создание главного виджета
    QWidget* mainWidget = new QWidget;
    // Создаём меню
    QAction *quit = new QAction(quitpix,"Закрыть..", this);// Создаем объект класса QAction с названием пункта меню "Закрыть"
    QAction *spravka = new QAction(spravkapix,"О программе..", this);// Создаем объект класса QAction с названием пункта меню "О программе"
    QMenu *file_inform;
    file_inform = menuBar()->addMenu("Файл");//Создаём первое подменю
    file_inform->addAction(quit);//Добавляем действие "Закрыть"
    file_inform = menuBar()->addMenu("Справка");//Создаём второе подменю
    file_inform->addAction(spravka);//Добавляем действие "О программе.."
    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);
    connect(quit, &QAction::triggered, qApp, QApplication::quit);//Когда в меню выбираем "Закрыть", то приложение автоматически закрывается
    connect(spravka, &QAction::triggered, this, &Window::showInform);//Когда в меню выбираем "Справка", то появляется окно "О программе..."
    this->setWindowTitle("Поиск максимального потока в транспортной сети");//Задаём название окна
    //Создание кнопкок и других виджетов
    btnCalc = new QPushButton("Вычислить \nмаксимальный поток",this);//Кнопка вычисления максимального потока
    btnPrint = new QPushButton("Последние\nвычисления",this);
    btnChange = new QPushButton("Изменить размер", this);//Кнопка изменения размера матрицы
    //Создание виджетов для функции измения размера
    text_size = new QLabel("Чтобы имзенить размер матрицы, введите нужное Вам число в поле ввода, после нажмите на кнопку 'Изменить размер'");//Пояснительный текст
    size_matrix = new QLabel("Поле ввода",this);//Пояснительный текст
    input_size = new QLineEdit("",this);//Поле для ввода размеры матрицы
    //Создание матрицы
    tableMatrix = new QTableWidget(n,n,this);
    tableMatrix->clear();
    //Изменяем название столбцов и строк
    for(i=1;i<=n;i++)
    {
        Label1='x';
        Label1.append(Label2.setNum(i));//в переменную "C" типа QString записываем число, преобразованное в строку
        name_table << Label1;//Заносим пременную "a" типа QString в QStringList
    }
    tableMatrix->setVerticalHeaderLabels(name_table);
    tableMatrix->setHorizontalHeaderLabels(name_table);
    tableMatrix->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableMatrix->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // Создаём виджеты для компоновки
    QVBoxLayout *layout = new QVBoxLayout();//Для компоновки кнопок "Вычислить", "Последние вычисления", "Выход"
    QHBoxLayout *layout1 = new QHBoxLayout();//Для компоновки кнопок и матрицы
    QVBoxLayout *layout2 = new QVBoxLayout();//Для компоновки поля ввода и пояснительного текста(razmer_matrix)
    QHBoxLayout *layout3 = new QHBoxLayout();//Для компоновки пояснительного текста(text_razmer) и layout2
    QHBoxLayout *layout4 = new QHBoxLayout();//Для добавления пространства между границей окна и кнопки изменения
    QVBoxLayout *layout_main = new QVBoxLayout(this);//Главный компоновщик
    //Компоновка виджетов
    layout->addWidget(btnCalc);
    layout->addWidget(btnPrint);
    layout1->addWidget(tableMatrix);
    layout1->addSpacing(10);
    layout1->addLayout(layout);
    layout3->addSpacing(200);
    layout3->addWidget(size_matrix);
    layout3->addWidget(input_size);
    layout3->addSpacing(200);
    layout2->addWidget(text_size);
    layout2->addLayout(layout3);
    layout4->addSpacing(250);
    layout4->addWidget(btnChange);
    layout4->addSpacing(250);
    layout2->addLayout(layout4);
    layout_main->addLayout(layout1);
    layout_main->addLayout(layout2);
    mainWidget->setLayout(layout_main);
    setCentralWidget(mainWidget);
    // Установка размеры окна
    resize(550,550);
     // Связывание сигналов от нажатия кнопок со слотами
    connect(btnChange,SIGNAL(clicked(bool)),
             this,SLOT(ChangeSize()));
    connect(btnCalc,SIGNAL(clicked(bool)),
             this,SLOT(showCalc()));
    connect(btnPrint, SIGNAL(clicked(bool)),
             this,SLOT(showPrint()));
}
//Функция, открывающая окно со справкой
void Window::showInform()
{
    winSpravka.show();//Открываем окно "О программе.."
}

//Функция, изменяющая размер матрицы
void Window::ChangeSize()
{
    //Проверка того, что ввёл пользователь в поле для изменения матрицы (число должно быть целого типа и больше 2)
    if ((input_size->text().toInt()) && (input_size->text().toInt()>2))
    {
        //Если пользователь ввёл верно число, то изменяем матрицу и её заголовки столбцов и строк
        name_table.clear();//Удаляем старые записи из name_table
        n=input_size->text().toInt();
        tableMatrix->setColumnCount(n);
        tableMatrix->setRowCount(n);
        tableMatrix->clear();
        for(i=1;i<=n;i++)
        {
            Label1='x';
            Label1.append(Label2.setNum(i));
            name_table << Label1;
        }
        tableMatrix->setVerticalHeaderLabels(name_table);
        tableMatrix->setHorizontalHeaderLabels(name_table);
        tableMatrix->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        tableMatrix->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
    else
    {
      //Если пользователь ввёл неверно, то возникате окно с ошибкой
      OutputMessage("Размер матрицы может быть целым числом больше 2",450);
    }
}
//Функция вычисления максимапльного потока в сети
void Window::showCalc()
{
    bool proverka=true;
    name_table.clear();
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
    {
     QTableWidgetItem *item = tableMatrix->item(i,j);
     //Проверяем, чтобы ячейка была непустой и целочисленного типа
     if ((item != NULL) && (item->text().toInt()>-1))
     {
       //Если пользователья ввёл верно, то заносим число в матрицу, предназначенную для вычислений
       matrix_algoritm[i][j]=item->text().toInt();
     }
     else
     {
       proverka=false;
       goto Finish;
     }
    }
    Finish:
    if (proverka)
    { //Если пользователь ввёл верно, то будет произведено вычисление
      CopyMatrix(matrix_algoritm,immutable_matrix,n);
      //Поиск источника и стока в сети
      int source = current_source(matrix_algoritm,n);
      int stock = current_stock(matrix_algoritm,n);
      if ((source != -1) && (stock != -1))
      {
        if (source != stock)
        {
            //Вычисление и сохранение резултатов, если источник и сток не совпали
            int result=max_flow(n,matrix_algoritm,0,n-1,matrix_flow);
            resultstr.setNum(result);
            for(i=0;i<n;i++)
            {
                int chg;
                chg = matrix_flow[i][0];
                matrix_flow[i][0] = matrix_flow[i][source];
                matrix_flow[i][source] = chg;
                chg = matrix_flow[n-1][i];
                matrix_flow[n-1][i] = matrix_flow[stock][i];
                matrix_flow[stock][i] = chg;
            }
            winResult.showAllResult(resultstr,source+1,stock+1,matrix_flow,n);
            addLastResults();
        }
        else
        {
          //Вычисление и сохранение резултатов, если источник и сток совпали
          resultstr.setNum(0);
          winResult.showAllResult(resultstr,source+1,stock+1,matrix_flow,n);
          addLastResults();
        }
      }
      else
      {
        OutputMessage("В исходной матрице отсутствует источник или сток \n\nИсточник - это вершина, в которую не входит ни одного ребра; \nСток - это вершина, из которой не выходит ни одного ребра;",550);
      }
    }
    else
    {
      OutputMessage("Исходная матрица может содержать только целые положительные числа или ноль",650);
    }
}

void Window::showPrint()
{
    winPrint.showAll();
}
//Функция добавления результатов вычисления в файл
void Window::addLastResults()
{
    bookFile book;
    recType r;
    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();
    r.current_date = cd.toString().append("\n").append(ct.toString());
    r.size.setNum(n);
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
          r.matrix.append(Label1.setNum(immutable_matrix[i][j])).append(" ");
      }
      r.matrix.append("\n");
    }
    r.results = resultstr;
    book.addRec(r);
}







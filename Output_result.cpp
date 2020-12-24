#include "Output_result.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
Output_result::Output_result(QWidget *parent)
    : QMainWindow(parent)
{
   QColor c=QColor(Qt::gray).lighter(155);
   QPalette palette = this->palette();
   palette.setColor(QPalette::Window,c);
   this->setPalette(palette);
   //Создание главного виджета
   QWidget *mainWidget = new QWidget;
   max_flow_text = new QLabel;
   source_text = new QLabel;
   stock_text = new QLabel;
   matrixflow_text = new QLabel;
   btnExit = new QPushButton("Ок",this);
   //Название окна
   this->setWindowTitle("Результат");
   //Создание виджетов для компоновки
   QHBoxLayout *layout2 = new QHBoxLayout;
   layout2->addSpacing(100);
   layout2->addWidget(btnExit);
   layout2->addSpacing(100);
   QVBoxLayout *layout_main = new QVBoxLayout(this);
   layout_main->addWidget(max_flow_text);
   layout_main->addWidget(source_text);
   layout_main->addWidget(stock_text);
   layout_main->addWidget(matrixflow_text);
   layout_main->addLayout(layout2);
   mainWidget->setLayout(layout_main);
   setCentralWidget(mainWidget);
   resize(300,200);// Изменени размера окна
   connect(btnExit, SIGNAL(clicked(bool)),
            this,SLOT(close()));
}
void Output_result::showAllResult(QString result, int source, int stock, int matrixflow[100][100],int size)
{
    max_flow_matrixflow.clear();
    max_flow_result.clear();
    max_flow_source.clear();
    max_flow_stock.clear();
    QFont font = max_flow_text->font();
    font.setPixelSize(17);
    max_flow_source.append("Источник: х").append(max_flow_stock.setNum(source));
    max_flow_stock.clear();
    max_flow_stock.append("Сток: х").append(max_flow_result.setNum(stock));
    max_flow_result.clear();
    max_flow_result.append("Максимальный поток: ").append(result);
    max_flow_matrixflow.append("Матрица потока:\n");
    for(int i=0;i<size;i++)
    {
      for(int j=0;j<size;j++)
      {
          max_flow_matrixflow.append(Label.setNum(matrixflow[i][j])).append(" ");
      }
      max_flow_matrixflow.append("\n");
    }
    max_flow_text->setText(max_flow_result);
    max_flow_text->setFont(font);
    source_text->setText(max_flow_source);
    source_text->setFont(font);
    stock_text->setText(max_flow_stock);
    stock_text->setFont(font);
    matrixflow_text->setText(max_flow_matrixflow);
    matrixflow_text->setFont(font);
    show();
    resize(300,200);
}

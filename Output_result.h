#ifndef INPUT_RESULT_H
#define INPUT_RESULT_H
#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
class Output_result : public QMainWindow
{
    Q_OBJECT
    QLabel *max_flow_text,*source_text,*stock_text,*matrixflow_text;
    QPushButton *btnExit;
public:
    QString max_flow_result, max_flow_source, max_flow_stock,max_flow_matrixflow,Label;
    Output_result(QWidget *parent=0);
    void showAllResult(QString result, int source, int stock, int matrixflow[100][100], int size);
};

#endif // INPUT_RESULT_H

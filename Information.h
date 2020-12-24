#ifndef SPRAVKA_H
#define SPRAVKA_H
#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
class Spravka: public QMainWindow
{
    Q_OBJECT
    QLabel *spravka_text;
    QPushButton *btnExit;
public:
    Spravka(QWidget *parent=0);
};

#endif // SPRAVKA_H

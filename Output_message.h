#ifndef OUTPUT_MESSAGE_H
#define OUTPUT_MESSAGE_H
#include <QMessageBox>
#include <QGridLayout>
//Вывод сообщения определённой длины
void OutputMessage(QString message, int width)
{
     QMessageBox  msgBox;
     msgBox.setWindowTitle("Ошибка");
     msgBox.setStandardButtons( QMessageBox::Ok );
     msgBox.setIcon(QMessageBox::Critical);
     QSpacerItem* horizontalSpacer = new QSpacerItem(width, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
     msgBox.setText(message);
     QGridLayout* layout = (QGridLayout*)msgBox.layout();
     layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
     msgBox.exec();
}
#endif // OUTPUT_MESSAGE_H

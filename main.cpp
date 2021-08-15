#include "mainwindow.h"
#include <QApplication>
#include "parking.h"

string id;
Car* carList[1000];
System sys;
int size=0, i, currentTime;
QString msg,state;

QLabel *l1,*l2,*l3,*l4;
QTableWidget* record;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QIcon icon("C:/Users/sunnn/Desktop/Qt-Parking-Lot-master/images/icon.png");
    w.setWindowIcon(icon);
    w.show();

    return a.exec();
}

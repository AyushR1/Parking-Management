#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enterdialog.h"
#include "leavedialog.h"
#include "parking.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QObject::tr("RGIPT Parking"));
    ui->freePlaces->setText(QString::number(MAX_CAR));
    ui->statusBar->showMessage("By Ayush Rathore");

    extern QLabel *l1,*l2,*l3,*l4;
    l1=ui->occupiedPlaces;
    l2=ui->freePlaces;
    l3=ui->countPas;
    l4=ui->totalEarnings;
    QPixmap pix("C:/Users/sunnn/Desktop/Qt-Parking-Lot-master/images/head.png");
    ui->picture->setPixmap(pix.scaled(285,165,Qt::KeepAspectRatio));
}

void MainWindow::updateMessage(QString msg)
{
    ui->message->append(msg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enter_clicked()
{
    enterDialog enterInput(this);
    enterInput.setWindowTitle("Vehicle Arival");
    enterInput.exec();
}

void MainWindow::on_leave_clicked()
{
    leaveDialog leaveInput(this);
    leaveInput.setWindowTitle("Departure");
    leaveInput.exec();
}

void MainWindow::closeEvent()
{
    extern int size;
    extern Car* carList[1000];
    for (int i = 0; i < size; i++){
        //cout<<"delete "<<carList[i]->getNumber()<<endl;
        delete carList[i];
    }
}

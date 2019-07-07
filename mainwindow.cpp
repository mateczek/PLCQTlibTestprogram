#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    plc=new PlcQtLib("192.168.0.10",1,sizeof(db),(unsigned char*)&db,2,0,0);
    connect(plc,SIGNAL(dataReady()),this,SLOT(readedData()));
    connect(plc,SIGNAL(finished()),plc,SLOT(start()));
    connect(plc,SIGNAL(connected(bool)),this,SLOT(connected(bool)));
    plc->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    plc->stopThread();
    plc->deleteLater();
}

void MainWindow::readedData()
{
    ui->lab_DBB->setText(QString::number(db._PLCbyte));
    ui->lab_DBW->setText(QString::number(PlcWORDtoInt(db._PLCword)));
    ui->lab_DBD->setText(QString::number(PlcDWORDtoInt(db._doubleWord)));
    ui->checkBox->setChecked(db.bit1);
    ui->checkBox_2->setChecked(db.bit2);
    ui->checkBox_3->setChecked(db.bit3);
}

void MainWindow::connected(bool b)
{
    ui->centralWidget->setEnabled(b);
    qDebug()<<"Połączono "<<b;
}
void MainWindow::on_button_bit1_Set_clicked(){
    plc->setBit(0,0);
}
void MainWindow::on_button_bit1_Reset_clicked(){
    plc->clearBit(0,0);
}

void MainWindow::on_button_bit2_Set_clicked(){
     plc->setBit(0,1);
}
void MainWindow::on_button_Bit2_Reset_clicked(){
    plc->clearBit(0,1);
}
void MainWindow::on_button_bit3_pressed(){
    plc->setBit(0,2);
}

void MainWindow::on_button_bit3_released(){
    plc->clearBit(0,2);
}
void MainWindow::on_push_DBB_clicked(){
    static int val = 0;
    val+=10;
    plc->writeByte(4,val);
}
void MainWindow::on_push_dbw_clicked(){
    static int val = 0;
    val+=100;
    plc->writeWord(2,val);
}
void MainWindow::on_push_DBD_clicked(){
    static int val = 0;
    val+=1000;
    plc->writeDword(6,val);
}













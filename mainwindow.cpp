#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    plc=new PlcQtLib("192.168.127.188",30,10,(unsigned char*)&db);
    connect(plc,SIGNAL(dataReady()),this,SLOT(readedData()));
    connect(plc,SIGNAL(finished()),plc,SLOT(start()));
    connect(plc,SIGNAL(connected(bool)),this,SLOT(connected(bool)));
    plc->start();
    qDebug()<<sizeof(db);
}

MainWindow::~MainWindow()
{
    delete ui;
    plc->stopThread();
    plc->deleteLater();
}

void MainWindow::readedData()
{
    ui->lineEdit->setText(QString::number(PlcWORDtoInt(db.dana)));
    ui->lineEdit_2->setText(QString::number(db.dana2));
    ui->lineEdit_4->setText(QString::number(PlcDWORDtoInt(db.b1)));
    ui->radioButton->setChecked(db.bit1);
    ui->radioButton_2->setChecked(db.bit2);
    ui->radioButton_3->setChecked(db.bit3);
    ui->radioButton_4->setChecked(db.bit4);
    ui->radioButton_5->setChecked(db.bit5);
    ui->radioButton_6->setChecked(db.bit6);
    ui->radioButton_7->setChecked(db.bit7);
    ui->radioButton_8->setChecked(db.bit8);
    ui->radioButton_9->setChecked(db.bit9);
    ui->radioButton_10->setChecked(db.bit10);
    ui->radioButton_11->setChecked(db.bit11);
    ui->radioButton_12->setChecked(db.bit12);
    ui->radioButton_13->setChecked(db.bit13);
    ui->radioButton_14->setChecked(db.bit14);
    ui->radioButton_15->setChecked(db.bit15);
    ui->radioButton_16->setChecked(db.bit16);
}

void MainWindow::connected(bool b)
{
    ui->centralWidget->setEnabled(b);
}

void MainWindow::on_pushButton_clicked()
{
    plc->writeWord(2,5000);
}

void MainWindow::on_pushButton_2_clicked()
{
    plc->writeByte(4,33);
}

void MainWindow::on_pushButton_3_clicked()
{
    int nr=ui->lineEdit_3->text().toInt()-1;

    plc->setBit((nr)/8,(nr)%8);
}

void MainWindow::on_pushButton_4_clicked()
{
    plc->writeDword(6,3333);
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"plcqtlib.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    #if defined(__MINGW32__)||defined(__MINGW64__)
    #pragma pack(push, 1)
    #endif
    struct{
      PlcBYTE bit1:1,bit2:1,bit3:1,bit4:1,bit5:1,bit6:1,bit7:1,bit8:1;
      PlcBYTE bit9:1,bit10:1,bit11:1,bit12:1,bit13:1,bit14:1,bit15:1,bit16:1;
      PlcWORD dana;
      PlcBYTE dana2;
      PlcBYTE free;
      PlcDWORD b1;
    }
    #if defined(__GNUC__)
    __attribute__((packed))
    #endif
    db;
    #if defined(__MINGW32__)||defined(__MINGW64__)
    #pragma pack(pop)
    #endif

    PlcQtLib *plc;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void readedData();
    void connected(bool);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

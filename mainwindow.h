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
      PlcBYTE bit1:1,bit2:1,bit3:1,bit4:1,bit5:1,bit6:1,bit7:1,bit8:1,:8;
      PlcWORD _PLCword;
      PlcBYTE _PLCbyte;
      PlcBYTE notUse;
      PlcDWORD _doubleWord;
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
    void on_push_DBD_clicked();
    void on_push_dbw_clicked();
    void on_push_DBB_clicked();

    void on_button_bit1_Reset_clicked();
    void on_button_Bit2_Reset_clicked();
    void on_button_bit1_Set_clicked();
    void on_button_bit2_Set_clicked();
    void on_button_bit3_pressed();
    void on_button_bit3_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

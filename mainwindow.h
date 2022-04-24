#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_But_toSet1_clicked();

    void on_But_toSet2_clicked();

    void on_But_Clear1_clicked();

    void on_But_Clear2_clicked();

    void on_But_Clear_Res_clicked();

    void on_But_Sub_clicked();

    void on_But_Mult_clicked();

    void on_But_Add_clicked();

    void on_Tint_clicked();

    void on_Tstr_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H





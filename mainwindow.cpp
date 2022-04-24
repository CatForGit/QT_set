#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Class_Set.cpp"

#include <QString>
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString S1 = "";
QString S2 = "";
QString Res = "";
int Type = -1;
std::vector<QString> str_buf;
my_set <QString> Str_Set_1;
my_set <QString> Str_Set_2;
std::vector<int> int_buf;
my_set <int> Int_Set_1;
my_set <int> Int_Set_2;


void MainWindow::on_But_toSet1_clicked() {
    if(Type == -1) {
        ui->Error->setText("Error: Select data type!");
        ui->Input->setText("");
    }
    else if(Type == 0) {
        ui->Error->setText("Error: No");
        QString temp = ui->Input->text();
        ui->Input->setText("");

        int Check = 1;
        std::string str = temp.toStdString();
        for (size_t i = 0; i < str.size(); ++i) {
            if (int(str[i]) < 48 || int(str[i]) > 57) Check = 0;
        }

        if(Check == 1) {
            int el = temp.toInt();
            Int_Set_1.push_el(el);
            S1.clear();
            Int_Set_1.Copy_set(int_buf);
            for(uint i = 0; i < int_buf.size(); i++){
                S1 += QString::number(int_buf[i]);
                S1 += "\n";
            }
            ui->Out_Set1 ->setText(S1);
        }
        else ui->Error->setText("Error: Inappropriate data type!");
    }
    else {
        ui->Error->setText("Error: No");
        QString temp = ui->Input->text();
        ui->Input->setText("");
        Str_Set_1.push_el(temp);
        S1.clear();
        Str_Set_1.Copy_set(str_buf);
        for(uint i = 0; i < str_buf.size(); i++){
            S1 += str_buf[i];
            S1 += "\n";
        }
        ui->Out_Set1 ->setText(S1);
    }
}

void MainWindow::on_But_toSet2_clicked() {
    if(Type == -1) {
        ui->Error->setText("Error: Select data type!");
        ui->Input->setText("");
    }
    else if(Type == 0) {
        ui->Error->setText("Error: No");
        QString temp = ui->Input->text();
        ui->Input->setText("");

        int Check = 1;
        std::string str = temp.toStdString();
        for (size_t i = 0; i < str.size(); ++i) {
            if (int(str[i]) < 48 || int(str[i]) > 57) Check = 0;
        }

        if(Check == 1) {
            int el = temp.toInt();
            Int_Set_2.push_el(el);
            S2.clear();
            Int_Set_2.Copy_set(int_buf);
            for(uint i = 0; i < int_buf.size(); i++){
                S2 += QString::number(int_buf[i]);
                S2 += "\n";
            }
            ui->Out_Set2 ->setText(S2);
        }
        else ui->Error->setText("Error: Inappropriate data type!");
    }
    else {
        ui->Error->setText("Error: No");
        QString temp = ui->Input->text();
        ui->Input->setText("");
        Str_Set_2.push_el(temp);
        S2.clear();
        Str_Set_2.Copy_set(str_buf);
        for(uint i = 0; i < str_buf.size(); i++){
            S2 += str_buf[i];
            S2 += "\n";
        }
        ui->Out_Set2 ->setText(S2);
    }
}

void MainWindow::on_But_Clear1_clicked(){
    S1.clear();
    ui->Out_Set1 ->setText(S1);
    if(Type == 0) Int_Set_1.Clear();
    else Str_Set_1.Clear();
}

void MainWindow::on_But_Clear2_clicked(){
    S2.clear();
    ui->Out_Set2 ->setText(S2);
    if(Type == 0) Int_Set_2.Clear();
    else Str_Set_2.Clear();
}

void MainWindow::on_But_Clear_Res_clicked(){
    Res.clear();
    ui->Out_Set_Res ->setText(Res);
    if(Type == 0)int_buf.clear();
    else str_buf.clear();
}

void MainWindow::on_But_Sub_clicked() {
    if(Type == -1) {
        ui->Error->setText("Error: Select data type!");
        ui->Input->setText("");
    }
    else if(Type == 0) {
        ui->Error->setText("Error: No");
        Int_Set_1.sim_sub(Int_Set_2,int_buf);
        Res.clear();
        for(uint i = 0; i < int_buf.size(); i++){
            Res += QString::number(int_buf[i]);
            Res += "\n";
        }
        ui->Out_Set_Res ->setText(Res);
    }
    else {
        ui->Error->setText("Error: No");
        Str_Set_1.sim_sub(Str_Set_2,str_buf);
        Res.clear();
        for(uint i = 0; i < str_buf.size(); i++){
            Res += str_buf[i];
            Res += "\n";
        }
        ui->Out_Set_Res ->setText(Res);
    }
}

void MainWindow::on_But_Mult_clicked() {
    if(Type == -1) {
        ui->Error->setText("Error: Select data type!");
        ui->Input->setText("");
    }
    else if(Type == 0) {
        ui->Error->setText("Error: No");
        Int_Set_1.mult(Int_Set_2,int_buf);
        Res.clear();
        for(uint i = 0; i < int_buf.size(); i++){
            Res += QString::number(int_buf[i]);
            Res += "\n";
        }
        ui->Out_Set_Res ->setText(Res);
    }
    else {
        ui->Error->setText("Error: No");
        Str_Set_1.mult(Str_Set_2,str_buf);
        Res.clear();
        for(uint i = 0; i < str_buf.size(); i++){
            Res += str_buf[i];
            Res += "\n";
        }
        ui->Out_Set_Res ->setText(Res);
    }
}

void MainWindow::on_But_Add_clicked() {
    if(Type == -1) {
        ui->Error->setText("Error: Select data type!");
        ui->Input->setText("");
    }
    else if(Type == 0) {
        ui->Error->setText("Error: No");
        Int_Set_1.add(Int_Set_2,int_buf);
        Res.clear();
        for(uint i = 0; i < int_buf.size(); i++){
            Res += QString::number(int_buf[i]);
            Res += "\n";
        }
        ui->Out_Set_Res ->setText(Res);
    }
    else {
        ui->Error->setText("Error: No");
        Str_Set_1.add(Str_Set_2,str_buf);
        Res.clear();
        for(uint i = 0; i < str_buf.size(); i++){
            Res += str_buf[i];
            Res += "\n";
        }
        ui->Out_Set_Res ->setText(Res);
    }
}

void MainWindow::on_Tint_clicked() {
    if(Type != 0) {
        ui->Tlabel ->setText("Type set: Integer");
        Type = 0;

        S1.clear();
        ui->Out_Set1 ->setText(S1);
        Int_Set_1.Clear();
        Str_Set_1.Clear();

        S2.clear();
        ui->Out_Set2 ->setText(S2);
        Int_Set_2.Clear();
        Str_Set_2.Clear();

        Res.clear();
        ui->Out_Set_Res ->setText(Res);
        int_buf.clear();
        str_buf.clear();
    }
}

void MainWindow::on_Tstr_clicked() {
    if(Type != 1) {
        ui->Tlabel ->setText("Type set: String");
        Type = 1;

        S1.clear();
        ui->Out_Set1 ->setText(S1);
        Int_Set_1.Clear();
        Str_Set_1.Clear();

        S2.clear();
        ui->Out_Set2 ->setText(S2);
        Int_Set_2.Clear();
        Str_Set_2.Clear();

        Res.clear();
        ui->Out_Set_Res ->setText(Res);
        int_buf.clear();
        str_buf.clear();
    }
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTableWidgetItem>

int cont = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->txt_alt->setVisible(false);
    ui->label_alt->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    switch (arg1){
    case 0:
    {
        ui->txt_alt->setVisible(false);
        ui->label_alt->setVisible(false);
        break;
    }
    case 2:
    {
        ui->txt_alt->setVisible(true);
        ui->label_alt->setVisible(true);
        break;
    }
    }
}


void MainWindow::on_pushButton_clicked()
{
    QString desc = ui->txt_desc->text();
    QString alt = ui->txt_alt->text();
    qDebug() << desc;
    qDebug() << alt;
    ui->tb_pernas->setColumnCount(2);
    ui->tb_pernas->setRowCount(cont+1);
    ui->tb_pernas->setItem(cont, 0, new QTableWidgetItem(desc));
    ui->tb_pernas->setItem(cont, 1, new QTableWidgetItem(alt));
    qDebug() << cont;
    cont++;
}


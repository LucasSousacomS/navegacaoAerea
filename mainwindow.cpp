#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTableWidgetItem>
#include <QStringList>

int cont = 0;
bool vor = 0;
bool alt = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->txt_alt->setVisible(false);
    ui->label_alt->setVisible(false);
    ui->lbl_freq->setVisible(false);
    ui->txt_freq->setVisible(false);
    ui->radio_curso->setVisible(false);
    ui->radio_radial->setVisible(false);
    ui->tb_pernas->setColumnCount(6);
    QStringList header = { "Finalizada", "Descrição", "Altitude final", "Rumo", "Fixo", "Frequência" };
    ui->tb_pernas->setHorizontalHeaderLabels(header);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString desc = ui->txt_desc->text();
    QString alt = ui->txt_alt->text();
    QString rumo = ui->txt_rumo->text();
    QString fixo = ui->txt_fixo->text();
    QString freq = ui->txt_freq->text();
    if(vor == 0){
        freq = "";
    }
    if(alt == 0){
        alt = "";
    }
    qDebug() << desc;
    qDebug() << alt;    
    ui->tb_pernas->setRowCount(cont+1);
    ui->tb_pernas->setCellWidget(cont, 0, new QCheckBox("", this));
    ui->tb_pernas->setItem(cont, 1, new QTableWidgetItem(desc));
    ui->tb_pernas->setItem(cont, 2, new QTableWidgetItem(alt));
    //ui->tb_pernas->setItem(cont, 2, new QTableWidgetItem(rumo));
    if(ui->radio_curso->isChecked() && vor == 1){
        qDebug() << "Curso";
        ui->tb_pernas->setItem(cont, 3, new QTableWidgetItem("Curso " + rumo));
    }else if(ui->radio_radial->isChecked() && vor == 1){
        qDebug() << "Radiel";
        ui->tb_pernas->setItem(cont, 3, new QTableWidgetItem("Radial " + rumo));
    }else{
        ui->tb_pernas->setItem(cont, 3, new QTableWidgetItem(rumo));
    }
    ui->tb_pernas->setItem(cont, 4, new QTableWidgetItem(fixo));
    ui->tb_pernas->setItem(cont, 5, new QTableWidgetItem(freq));
    qDebug() << cont;
    cont++;
}


void MainWindow::on_chk_alt_stateChanged(int arg1)
{
    switch (arg1){
    case 0:
    {
        ui->txt_alt->setVisible(false);
        ui->label_alt->setVisible(false);
        alt = 0;
        break;
    }
    case 2:
    {
        ui->txt_alt->setVisible(true);
        ui->label_alt->setVisible(true);
        alt = 1;
        break;
    }
    }
}


void MainWindow::on_chk_vor_stateChanged(int arg1)
{
    qDebug() << arg1;
    switch (arg1){
    case 0:
    {
        ui->lbl_freq->setVisible(false);
        ui->txt_freq->setVisible(false);
        ui->radio_curso->setVisible(false);
        ui->radio_radial->setVisible(false);
        vor = 0;
        break;
    }
    case 2:
    {
        ui->lbl_freq->setVisible(true);
        ui->txt_freq->setVisible(true);
        ui->radio_curso->setVisible(true);
        ui->radio_radial->setVisible(true);
        vor = 1;
        break;
    }
    }
}


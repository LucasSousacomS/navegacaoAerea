#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_checkBox_stateChanged(int arg1);

    void on_pushButton_clicked();

    void on_chk_alt_stateChanged(int arg1);

    void on_chk_vor_stateChanged(int arg1);

    void on_actionSalvar_como_triggered();

    void on_actionAbrir_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rsa.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_genPass_clicked();
    long MacValue(QString);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Rsa rsa;
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QNetworkInterface>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

long MainWindow::MacValue(QString pi)
{
    long w =0;
    for(int i=0;i<pi.size();i++)
    {
        char p = pi.toLatin1().data()[i];
        w = w+p;
    }
    qDebug()<<tr("gen need rsa:%1").arg(w);
    return w;
}
//Gen
void MainWindow::on_genPass_clicked()
{

}


void MainWindow::on_pushButton_clicked()
{
    QString pi = ui->lineEdit->text();
    long need_encryption = MacValue(pi);
    Key key  = rsa.produce_keys();
    long publickey = key.pkey;
    long decode = key.dkey;
    long encode = key.ekey;
    long pass = rsa.endecrypt(need_encryption,encode,publickey);
    QString savefile = tr("%1-%2-%3").arg(publickey).arg(decode).arg(pass);
    QString filepath = QFileDialog::getSaveFileName(this,tr("Save File"),".",tr("File (*.txt)"));
    QFile files(filepath);
    if(!files.open(QIODevice::ReadWrite))
    {
        QMessageBox::information(this,tr("Notice"),tr("Not open the file."));
    }
    files.write(savefile.toLatin1());
    files.close();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QNetworkInterface>
#include <QMessageBox>

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
//Mac--->base64---->all add ==== the user code
void MainWindow::GenCode()
{
    QList<QNetworkInterface> NetList;
    int NetCount = 0;
    int Neti = 0;
    QNetworkInterface thisNet;
    NetList = QNetworkInterface::allInterfaces();
    NetCount = NetList.count();
    for(Neti = 0;Neti < NetCount; Neti++)
    {
        if(NetList[Neti].isValid())
        {
            thisNet = NetList[Neti];
            break;
        }
    }
    qDebug()<<thisNet.hardwareAddress();
    QString po = thisNet.hardwareAddress();
    QString pi = po.toLatin1().toBase64();
    qDebug()<<"first :"<<pi;
    ui->usercode->setText(pi);
    ui->machinecode->setText(pi);
    qDebug()<<pi;
    long y = MacValue(pi);
    qDebug()<<tr("Now i = %1").arg(y);
}
void MainWindow::GenKey()
{


}
//encode the user code
void MainWindow::Encode()
{

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
    GenCode();
    //the encode
    Key key = rsa.produce_keys();
    qDebug() << "After rsa,we get:"<< endl;
    qDebug() << "public key :" << key.pkey << endl;
    qDebug() << "encode key :" << key.ekey << endl;
    qDebug() << "decode key :" << key.dkey << endl;
    ui->publish->setText(tr("%1").arg(key.pkey));
    ui->encode->setText(tr("%1").arg(key.ekey));
    ui->decode->setText(tr("%1").arg(key.dkey));
    QString pi = ui->usercode->text();
    long w = MacValue(pi);

    qDebug()<<tr("gen need rsa:%1").arg(w);
    //encoder the number
    long msg_des = rsa.endecrypt(w, key.ekey, key.pkey);
    ui->passcode->setText(tr("%1").arg(msg_des));

    //User code

}

//login it
void MainWindow::on_pushButton_clicked()
{

    long decode = ui->decode2->text().toLong();
    long publickey = ui->publickkey->text().toLong();
    long knowresult = ui->passcode2->text().toLong();
    long result = rsa.endecrypt(knowresult,decode,publickey);

    QString pi = ui->machinecode->text();
    long y = MacValue(pi);

    qDebug()<<tr("result of signal:%1").arg(result);
    if(result==y)
    {
        QMessageBox::information(this,tr("Notice"),tr("Login successful"));
    }
}

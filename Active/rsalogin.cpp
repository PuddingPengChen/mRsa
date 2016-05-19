#include <QNetworkInterface>
#include <QMessageBox>
#include <QSettings>

#include "rsalogin.h"
#include "ui_rsalogin.h"


RsaLogin::RsaLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RsaLogin)
{
    ui->setupUi(this);
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
    QString po = thisNet.hardwareAddress();
    QString pi = po.toLatin1().toBase64();
    ui->machinecode->setText(pi);
    this->setWindowTitle(tr("RAS-Login"));
}

RsaLogin::~RsaLogin()
{
    delete ui;
}


long RsaLogin::MacValue()
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
    QString po = thisNet.hardwareAddress();
    QString pi = po.toLatin1().toBase64();

    long w =0;
    for(int i=0;i<pi.size();i++)
    {
        char p = pi.toLatin1().data()[i];
        w = w+p;
    }
    return w;
}

//active it
void RsaLogin::on_active_clicked()
{
    long pubkey = ui->publickey->text().toLong();
    long deckey = ui->decodekey->text().toLong();
    long paskey = ui->password->text().toLong();
    long result = rsa.endecrypt(paskey,deckey,pubkey);
    long macvalue = MacValue();
    if(result==macvalue)
    {
        //save it in the config.ini
        QSettings* settings = new QSettings("reg.ini",QSettings::IniFormat);
        settings->beginGroup("reg");
        settings->setValue("pubkey",(int)pubkey);
        settings->setValue("deckey",(int)deckey);
        settings->setValue("paskey",(int)paskey);
        settings->endGroup();
        //remind register successful
        QMessageBox::information(this,tr("Notice"),tr("Active successful!"));
    }
}

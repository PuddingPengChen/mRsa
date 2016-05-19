#include <QApplication>
#include <QMessageBox>
#include <QSettings>

#include "rsalogin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RsaLogin w;
    QSettings* settings = new QSettings("reg.ini",QSettings::IniFormat);
    settings->beginGroup("reg");
    int pubkey = settings->value("pubkey").toInt();
    int deckey = settings->value("deckey").toInt();
    int paskey = settings->value("paskey").toInt();
    settings->endGroup();
    long macvalue = w.MacValue();
    long result = w.rsa.endecrypt((long)paskey,(long)deckey,(long)pubkey);
    if(macvalue!=result)
    {
        w.show();
    }
    else
    {
        QMessageBox::information(NULL,QObject::tr("Notice"),QObject::tr("Login normal!"));

    }
    return a.exec();
}

#ifndef RSALOGIN_H
#define RSALOGIN_H

#include <QWidget>
#include "rsa.h"

namespace Ui {
class RsaLogin;
}

class RsaLogin : public QWidget
{
    Q_OBJECT

public:
    explicit RsaLogin(QWidget *parent = 0);
    ~RsaLogin();
    long MacValue();
    Rsa rsa;
private slots:
    void on_active_clicked();

private:
    Ui::RsaLogin *ui;
    long publickey;
    long decodekey;
    long passkey;
    long Passvalue;



};

#endif // RSALOGIN_H

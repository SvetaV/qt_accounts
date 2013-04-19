#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>
#include <QString>
#include <QDate>

class Account : public QObject
{
    Q_OBJECT
private:
    QString payer;
    QString payee;
    QString accountType;
    double amount;
    QDate date;
public:
    explicit Account(const QString &payer, const QString &payee, const QString &accountType, double amount, const QDate &date, QObject *parent = 0);
    QString getPayer()const;
    QString getPayee()const;
    QString getType()const;
    double getAmount()const;
    QDate getDate()const;

    void setPayer(const QString &payer);
    void setPayee(const QString &payee);
    void setType(const QString &accountType);
    void setAmount(const double amount);
    void setDate(const QDate &date);
//signals:
    
//public slots:
    
};

#endif // ACCOUNT_H

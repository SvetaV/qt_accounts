#include "account.h"

Account::Account(const QString &payer, const QString &payee, const QString &accountType, double amount, const QDate &date, QObject *parent) :
    QObject(parent)
{
    this->payer = payer;
    this->payee = payee;
    this->accountType = accountType;
    this->amount = amount;
    this->date = date;
}

QString Account::getPayer()const
{
    return this->payer;
}

QString Account::getPayee()const
{
    return this->payee;
}

QString Account::getType()const
{
    return this->accountType;
}

double Account::getAmount() const
{
    return this->amount;
}

QDate Account::getDate()const
{
    return this->date;
}

void Account::setPayer(const QString &payer)
{
    this->payer=payer;
}

void Account::setPayee(const QString &payee)
{
    this->payee=payee;
}

void Account::setType(const QString &accountType)
{
    this->accountType=accountType;
}

void Account::setAmount(const double amount)
{
    this->amount=amount;
}

void Account::setDate(const QDate &date)
{
    this->date = date;
}

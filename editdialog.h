#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QDateEdit>
#include <QDialogButtonBox>
#include <QFormLayout>

//#include "view.h"
#include "account.h"
//#include "accountlist.h"

class EditDialog : public QDialog
{
    Q_OBJECT
private:
    QLineEdit *payerEdit;
    QLineEdit *payeeEdit;
    QComboBox *typeEdit;
    QDoubleSpinBox *amountEdit;
    QDateEdit *dateEdit;
    QDialogButtonBox *editDialogButtons;
    void createWidgets();
    void createComboBox();
    void placeWidgets();
    void connectSlots();
public:
    explicit EditDialog(/*Account *account, */QWidget *parent = 0);
    //void setAccount(Account &account);
    QString getPayer()const;
    QString getPayee()const;
    QString getType()const;
    double getAmount()const;
    QDate getDate()const;
signals:
    
public slots:
    
};

#endif // EDITDIALOG_H

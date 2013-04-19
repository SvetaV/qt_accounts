#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QLabel>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

//#include "account.h"
#include "editdialog.h"
//#include "accountlist.h"

class View : public QWidget
{
    Q_OBJECT
private:
    QLabel *payer, *payee, *accType, *amount, *date;
    Account *account;
    //AccountList *accountList;
    void placeWidgets();
    void createLabels();
public:
    explicit View(QWidget *parent = 0);
    void setView(Account *newAccount);   
private slots:
    void editDialog();
};

#endif // VIEW_H

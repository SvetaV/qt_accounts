#include "view.h"

View::View(QWidget *parent) :
    QWidget(parent)
{
    createLabels();
    Account newAccount("payer1", "payee1", "type1", 15, QDate(2013,4,18));

    setView(&newAccount);

    placeWidgets();
}

void View::placeWidgets()
{
    QFormLayout *accountViewLayout = new QFormLayout;
    accountViewLayout->addRow("Payer name: ", payer);
    accountViewLayout->addRow("Payee name: ", payee);
    accountViewLayout->addRow("Type: ", accType);
    accountViewLayout->addRow("Amount: ", amount);
    accountViewLayout->addRow("Date: ", date);

    QPushButton *editButton = new QPushButton("Edit");
    QPushButton *exitButton = new QPushButton("Exit");
    QHBoxLayout *buttons = new QHBoxLayout;
    buttons->addWidget(editButton);
    buttons->addWidget(exitButton);

    QObject::connect(exitButton,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(editButton,SIGNAL(clicked()),this,SLOT(editDialog()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(accountViewLayout);
    mainLayout->addLayout(buttons);
    setLayout(mainLayout);

    setWindowTitle("Account");
}

void View::createLabels()
{
    payer = new QLabel;
    payee = new QLabel;
    accType = new QLabel;
    amount = new QLabel;
    date = new QLabel;
}

void View::editDialog()
{
    EditDialog *dialog = new EditDialog;
    if(dialog->exec() == QDialog::Accepted){
        account->setPayer(dialog->getPayer());
        account->setPayee(dialog->getPayee());
        //account->setType(dialog->getType());//error!
        account->setAmount(dialog->getAmount());
        account->setDate(dialog->getDate());

        setView(account);

        /*QLabel *new_label2 = new QLabel;
        new_label2->setNum(account->getAmount());
        new_label2->show();*/
    }
}

void View::setView(Account *newAccount)
{
    account=newAccount;
    payer->setText(newAccount->getPayer());
    payee->setText(newAccount->getPayee());
    //accType->setText(newAccount->getType());//error!
    amount->setNum(newAccount->getAmount());
    date->setText(newAccount->getDate().toString("dd.MM.yyyy"));
}


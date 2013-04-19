#include "editdialog.h"

EditDialog::EditDialog(/*Account* account, */QWidget *parent) :
    QDialog(parent)
{
    createWidgets();
    createComboBox();
    connectSlots();
    placeWidgets();
    //setAccount(&account);
    setWindowTitle("Edit");
}

void EditDialog::createWidgets()
{
    payerEdit = new QLineEdit;
    payeeEdit = new QLineEdit;
    amountEdit = new QDoubleSpinBox;
    amountEdit->setMinimum(0.1);
    dateEdit = new QDateEdit;
    dateEdit->setCalendarPopup(true);
    editDialogButtons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
}

void EditDialog::createComboBox()
{
    typeEdit = new QComboBox;
    QStringList typeList;
    typeList<<"type 1"<<"type 2"<<"type 3";
    typeEdit->addItems(typeList);
}

void EditDialog::placeWidgets()
{
    QFormLayout *mainLayout = new QFormLayout;
    mainLayout->addRow("Payer name: ", payerEdit);
    mainLayout->addRow("Payee name: ", payeeEdit);
    mainLayout->addRow("Type: ", typeEdit);
    mainLayout->addRow("Amount: ", amountEdit);
    mainLayout->addRow("Date", dateEdit);
    mainLayout->addRow(editDialogButtons);
    setLayout(mainLayout);
}
void EditDialog::connectSlots()
{
    connect(editDialogButtons,SIGNAL(accepted()),this,SLOT(accept()));
    connect(editDialogButtons,SIGNAL(rejected()),this,SLOT(reject()));
}

/*void EditDialog::setAccount(Account &account)
{
    payerEdit->setText(account->getPayer());
    payeeEdit->setText(account->getPayee());
    amountEdit->setValue(account->getAmount());
}*/

QString EditDialog::getPayer()const
{
    return payerEdit->text();
}

QString EditDialog::getPayee()const
{
    return payeeEdit->text();
}

QString EditDialog::getType()const
{
    return typeEdit->currentText();
}

double EditDialog::getAmount()const
{
    return amountEdit->value();
}

QDate EditDialog::getDate()const
{
    return dateEdit->date();
}

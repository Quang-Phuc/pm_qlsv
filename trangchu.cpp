#include "trangchu.h"
#include "ui_trangchu.h"

trangchu::trangchu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trangchu)
{
    ui->setupUi(this);
}

trangchu::~trangchu()
{
    delete ui;
}

#include "phuc1.h"
#include "ui_phuc1.h"

phuc1::phuc1(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::phuc1)
{
    ui->setupUi(this);
}

phuc1::~phuc1()
{
    delete ui;
}

#include "quanlythongtin.h"
#include "ui_quanlythongtin.h"
#include "themthongtin.h"

quanlythongtin::quanlythongtin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::quanlythongtin)
{
    ui->setupUi(this);
}

quanlythongtin::~quanlythongtin()
{
    delete ui;
}

void quanlythongtin::on_pushButton_clicked()
{
}

#include "quanlylophoc.h"
#include "ui_quanlylophoc.h"
#include "themlophoc.h"

quanlylophoc::quanlylophoc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::quanlylophoc)
{
    ui->setupUi(this);
}

quanlylophoc::~quanlylophoc()
{
    delete ui;
}

void quanlylophoc::on_pushButton_clicked()
{
}

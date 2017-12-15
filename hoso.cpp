#include "hoso.h"
#include "ui_hoso.h"
#include <QMessageBox>
#include <QFile>
#include <QString>
#include "khoacntt.h"
hoso::hoso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hoso)
{
    ui->setupUi(this);
}

hoso::~hoso()
{
    delete ui;
}
void hoso::on_bu_timkiem_clicked()
{
    KhoaCNTT conn;
    QString timkiem;
    timkiem=ui->timkiem5->text();
    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQueryModel * modal3= new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry= new QSqlQuery(conn.mydb);
    QSqlQuery* qry3= new QSqlQuery(conn.mydb);
    qry->prepare("select * from QLthongtin where Masv='"+timkiem+"'");
    qry3->prepare("select * from QLketquahoctap where Masv='"+timkiem+"'");
    qry->exec();
    qry3->exec();
    modal->setQuery(*qry);
    modal3->setQuery(*qry3);
    ui->tableView->setModel(modal);
    ui->ketquahoctap->setModel(modal3);
    conn.connClose();
    qDebug()<<(modal->rowCount());
    qDebug()<<(modal3->rowCount());
}

void hoso::on_pushButton_clicked()
{
    close();
}

#include "quenmatkhau.h"
#include "ui_quenmatkhau.h"
#include "themlophoc.h"
#include "ui_themlophoc.h"
#include "khoacntt.h"
#include <QMessageBox>
#include <QFile>
#include <QString>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<fstream>
#include<cstdlib>
#include <QAxObject>
#include <QMainWindow>
#include<QtDebug>
#include<QFileInfo>
#include <QSqlDatabase>
#include <QApplication>
#include<QtSql>
#include "doimatkhau.h"
#include   <QFileDialog>


Quenmatkhau::Quenmatkhau(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Quenmatkhau)
{
    ui->setupUi(this);
}

Quenmatkhau::~Quenmatkhau()
{
    delete ui;
}

void Quenmatkhau::on_timmatkhau_clicked()
{
    KhoaCNTT conn;
    QString TaiKhoan,Email;
    TaiKhoan=ui->taikhoan->text();
    Email=ui->email->text();
    QSqlQueryModel * modal= new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry= new QSqlQuery(conn.mydb);
    qry->prepare("select Matkhau from Dangnhap where TaiKhoan='"+TaiKhoan+"' and Email='"+Email+"'");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
}

void Quenmatkhau::on_doimatkhau_clicked()
{
    Doimatkhau doimk;
    doimk.setModal(true);
    doimk.exec();
}

void Quenmatkhau::on_thoat_clicked()
{
     close();
}

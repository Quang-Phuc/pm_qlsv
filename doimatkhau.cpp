#include "doimatkhau.h"
#include "ui_doimatkhau.h"
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
#include "include_cpp\libxl.h"
#include   <QFileDialog>


Doimatkhau::Doimatkhau(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Doimatkhau)
{
    ui->setupUi(this);
}

Doimatkhau::~Doimatkhau()
{
    delete ui;
}

void Doimatkhau::on_thaydoi_clicked()
{
    KhoaCNTT conn;
    QString Matkhaucu, Matkhaumoi,Matkhaumoi2;
    Matkhaucu=ui->mkhientai->text();
    Matkhaumoi=ui->mkmoi->text();
    Matkhaumoi2=ui->mkmoi2->text();

    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    if(Matkhaucu==""||Matkhaumoi==""||Matkhaumoi2=="")
    {
        QMessageBox::information(this,tr("Thông báo"),tr("Khong duoc de trong"));
    }
    else
    {
        if(Matkhaumoi==Matkhaumoi2)
        {
        qry.prepare("update Dangnhap set Matkhau='"+Matkhaumoi+"' where Matkhau='"+Matkhaucu+"' ");
        }
        else
        {
            QMessageBox::information(this,tr("Thông báo"),tr("Mật khẩu không khớp!"));
        }
    }
    if(qry.exec( ))
    {

        QMessageBox::information(this,tr("Thông báo"),tr("sửa thành công thông tin thành công"));
        conn.connClose();

    }
    else
    {
        QMessageBox::information(this,tr("Lỗi "),qry.lastError().text());
    }

}

void Doimatkhau::on_thoat_clicked()
{
    // close();

}

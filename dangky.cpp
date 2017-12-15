#include "dangky.h"
#include "ui_dangky.h"
#include "khoacntt.h"
#include <QMessageBox>

#include "themlophoc.h"
#include "ui_themlophoc.h"
#include "khoacntt.h"

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



Dangky::Dangky(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dangky)
{
    ui->setupUi(this);
}

Dangky::~Dangky()
{
    delete ui;
}

void Dangky::on_pushButton_2_clicked()
{


}

void Dangky::on_dangky_clicked()
{
    KhoaCNTT conn;
     QString Hoten, Email,TaiKhoan,MatKhau,Matkhau2;
     Hoten=ui->hoten->text();
     Email=ui->email->text();
     TaiKhoan=ui->taikhoan->text();
     MatKhau=ui->matkhau->text();
     Matkhau2=ui->nhaplaimatkhau->text();

     if(!conn.connOpen())
     {
         qDebug()<<"Failed to open the database";
         return;



     }

     conn.connOpen();
     QSqlQuery qry;
     if(Hoten=="")
     {
         QMessageBox::information(this,tr("Thông báo"),tr("Khong duoc de trong"));
     }
     else

     {
      if(MatKhau==Matkhau2)
      {
     qry.prepare("insert into Dangnhap (TaiKhoan,Matkhau,Hoten,Email,Matkhau2) values ('"+TaiKhoan+"','"+MatKhau+"','"+Hoten+"','"+Email+"','"+Matkhau2+"')");
      }
      else
      {
         QMessageBox::information(this,tr("Thông báo"),tr("Mật khẩu không trùng khớp"));
      }
      }
     if(qry.exec( ))
     {

        QMessageBox::information(this,tr("Thông báo"),tr("Chúc mừng bạn đã đăng ký thành công"));
        conn.connClose();

     }
     else
     {
          QMessageBox::information(this,tr("Lỗi "),qry.lastError().text());
     }
}

void Dangky::on_huybo_clicked()
{
    close();
  //  Quenmatkhau quenmk;
  //  PHUC p;
  //  PHUC p;
 //   p.setMouseTracking();
  //  p.setModal(true);
  //  p.exec();
  //  quenmk.setModal(true);
 //   quenmk.exec();
   // phuc p;
   // p.setMo
}

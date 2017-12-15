#include "themthongtin.h"
#include "ui_themthongtin.h"
#include "khoacntt.h"
#include <QMessageBox>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include "include_cpp\libxl.h"


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
using namespace libxl;
using namespace std;
themthongtin::themthongtin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::themthongtin)
{
    ui->setupUi(this);
    KhoaCNTT conn;
    if(!conn.connOpen())
        ui->tinhtrang->setText("Faile to open the database");
    else
        ui->tinhtrang->setText("Connetcted...");
}

themthongtin::~themthongtin()
{
    delete ui;
}




void themthongtin::on_Load_clicked()
{
    KhoaCNTT conn;
    QSqlQueryModel * modal= new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry= new QSqlQuery(conn.mydb);
    qry->prepare("select * from QLthongtin");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
}
void themthongtin::on_timkiem_clicked()
{
    KhoaCNTT conn;
    QString timkiem;
    timkiem=ui->timkiem4->text();
    QSqlQueryModel * modal= new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry= new QSqlQuery(conn.mydb);
    qry->prepare("select * from QLthongtin where Masv='"+timkiem+"'");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
}

void themthongtin::on_bt_sua_clicked()
{
    KhoaCNTT conn;
    QString Masv, Tensv,Giotinh,SDT,Email,Diachi;
    Masv=ui->masv->text();
    Tensv=ui->tensv->text();
    Giotinh=ui->gioitinh->text();
    SDT=ui->sdt->text();
    Email=ui->email->text();
    Diachi=ui->diachi->text();
    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    if(Masv==""||Tensv==""||Diachi=="")
    {
        QMessageBox::information(this,tr("Thông báo"),tr("Khong duoc de trong"));
    }
    else
    {
        qry.prepare("update QLthongtin set Masv='"+Masv+"',Tensv='"+Tensv+"',Gioitinh='"+Giotinh+"',SDT='"+SDT+"',Email='"+Email+"',Diachi='"+Diachi+"' where Masv='"+Masv+"' ");
    }
    if(qry.exec( ))
    {
        QMessageBox::information(this,tr("Thông báo"),tr("Bạn đã sửa thông tin thành công"));
        conn.connClose();
    }
    else
    {
        QMessageBox::information(this,tr("Lỗi "),qry.lastError().text());
    }
}

void themthongtin::on_bt_xoa_clicked()
{
    KhoaCNTT conn;
    QString Masv, Tensv,Giotinh,SDT,Email,Diachi;
    Masv=ui->masv->text();
    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from QLthongtin  where Masv='"+Masv+"' ");
    if(qry.exec( ))
    {
        QMessageBox::information(this,tr("Thông báo"),tr("Bạn đã xóa thông tin thành công"));
        conn.connClose();
    }
    else
    {
        QMessageBox::information(this,tr("Lỗi "),qry.lastError().text());
    }
}

void themthongtin::on_bt_them_clicked()
{
    KhoaCNTT conn;
    QString Masv, Tensv,Giotinh,SDT,Email,Diachi;
    Masv=ui->masv->text();
    Tensv=ui->tensv->text();
    Giotinh=ui->gioitinh->text();
    SDT=ui->sdt->text();
    Email=ui->email->text();
    Diachi=ui->diachi->text();
    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    if(Masv==""||Tensv==""||Diachi=="")
    {
        QMessageBox::information(this,tr("Thông báo"),tr("Khong duoc de trong"));

    }
    else
    {
        qry.prepare("insert into QLthongtin (Masv,Tensv,Gioitinh,SDT,Email,Diachi) values ('"+Masv+"','"+Tensv+"','"+Giotinh+"','"+SDT+"','"+Email+"','"+Diachi+"')");
    }
    if(qry.exec( ))
    {
        QMessageBox::information(this,tr("Thông báo"),tr("Thêm thông tin thành công"));
        conn.connClose();
    }
    else
    {

        QMessageBox::information(this,tr("Lỗi "),qry.lastError().text());
    }
}

void themthongtin::on_bt_laydl_clicked()
{
    QString filename=QFileDialog::getOpenFileName(
                this,
                tr("Open FIle "),
                "C://",
                "All file(*.*);;Text File(*.txt)"

                );
    QMessageBox::information(this,tr("File name"),filename);

    const wchar_t* ss;
    const wchar_t* s_msv;
    const wchar_t* s_tsv;

    const wchar_t* s_gt;
    const wchar_t* s_email;
    const wchar_t* s_dc;
     QString sdt;
    QString masinhvien;
    QString tensinhvien;

    QString gioitinh;
    QString email;
    QString diachi;

    QString sosanh;
   Book* book = xlCreateXMLBook();/// dinh dang cua xlsx
    if (book) {
        // L"d:\\phuc2.xlsx"
        std::string str = filename.toStdString();
      wstring a(str.begin(),str.end());
     const wchar_t* filename2 = a.c_str();
        if(book->load(filename2)) {
            Sheet* sheet = book->getSheet(0);// lay sheet nao
            if (sheet) {
                for(int row = sheet->firstRow(); row < sheet->lastRow(); ++row)
                {

                    for(int col = sheet->firstCol(); col < sheet->lastCol(); ++col)
                    {
                        ss=sheet->readStr(row, col);
                        wstring wss(ss);
                        string strs(wss.begin(), wss.end());
                        sosanh=strs.c_str();

                        if(sosanh=="MaSV")
                        {
                            int b=row;
                            int v=col;

                            for(int c= b+1; c < sheet->lastRow(); ++c)
                            {
                                s_msv = sheet->readStr(c, v);
                                wstring ws_msv(s_msv);
                                string str_msv(ws_msv.begin(), ws_msv.end());
                                masinhvien=str_msv.c_str();
                                std::wcout << std::endl;

                                s_tsv = sheet->readStr(c, v+1);
                                std::wcout << std::endl;
                                wstring ws_tsv(s_tsv);
                                string str_tsv(ws_tsv.begin(), ws_tsv.end());
                                tensinhvien=str_tsv.c_str();



                                s_gt = sheet->readStr(c, v+3);
                                std::wcout << std::endl;
                                wstring ws_gt(s_gt);
                                string str_gt(ws_gt.begin(), ws_gt.end());
                                gioitinh=str_gt.c_str();

                                double dt = sheet->readNum(c, v+4);
                                sdt=QString::number(dt);

                                s_email = sheet->readStr(c, v+5);
                                std::wcout << std::endl;
                                wstring ws_email(s_email);
                                string str_email(ws_email.begin(), ws_email.end());
                                email=str_email.c_str();

                                s_dc = sheet->readStr(c, v+6);
                                std::wcout << std::endl;
                                wstring ws_dc(s_dc);
                                string str_dc(ws_dc.begin(), ws_dc.end());
                                diachi=str_dc.c_str();

                                 KhoaCNTT conn;

                                if(!conn.connOpen())
                                {
                                    qDebug()<<"Failed to open the database";
                                    return;
                                }

                                conn.connOpen();
                                QSqlQuery qry;


                                     qry.prepare("insert into QLthongtin (Masv,Tensv,Gioitinh,SDT,Email,Diachi) values ('"+masinhvien+"','"+tensinhvien+"','"+gioitinh+"','"+sdt+"','"+email+"','"+diachi+"')");

                                if(!qry.exec( ))
                                {
                                     QMessageBox::information(this,tr("Lỗi "),qry.lastError().text());
                                    conn.connClose();
                                }

                                 conn.connClose();

                                //






                            }
                        }
                    }
                }

            }
        }
    }

    book->release();


}



void themthongtin::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();
      KhoaCNTT conn;
      if(!conn.connOpen())
      {
          qDebug()<<"Failed to open the database";
          return;
      }
      conn.connOpen();
      QSqlQuery qry;
         qry.prepare("select * from QLthongtin where Masv='"+val+"' or Tensv='"+val+"' or Gioitinh='"+val+ "' or SDT='"+val+"' or Email='"+val+"' or Diachi='"+val+"'");
         if(qry.exec( ))
         {
            while(qry.next())
            {
                ui->masv->setText(qry.value(0).toString());
                 ui->tensv->setText(qry.value(1).toString());
                  ui->gioitinh->setText(qry.value(2).toString());
                   ui->sdt->setText(qry.value(3).toString());
                    ui->email->setText(qry.value(4).toString());
                     ui->diachi->setText(qry.value(5).toString());
            }
             conn.connOpen();
         }
         else
         {
             QMessageBox::critical(this,tr("Error :"), qry.lastError().text());
         }

}

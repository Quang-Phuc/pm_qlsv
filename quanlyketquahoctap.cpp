#include "quanlyketquahoctap.h"
#include "ui_quanlyketquahoctap.h"
#include "khoacntt.h"
#include <QMessageBox>
#include "include_cpp\libxl.h"
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
#include   <QFileDialog>
using namespace libxl;
using namespace std;
quanlyketquahoctap::quanlyketquahoctap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::quanlyketquahoctap)
{
    ui->setupUi(this);
}

quanlyketquahoctap::~quanlyketquahoctap()
{
    delete ui;
}

void quanlyketquahoctap::on_Timkiem_clicked()
{
    KhoaCNTT conn;
    QSqlQueryModel * modal3= new QSqlQueryModel();
    conn.connOpen();
    QString timkiem;
    timkiem=ui->timkiem2->text();
    QSqlQuery* qry3= new QSqlQuery(conn.mydb);
    qry3->prepare("select * from QLketquahoctap where Mamon='"+timkiem+"'");
    qry3->exec();
    modal3->setQuery(*qry3);
    ui->tableView->setModel(modal3);
    conn.connClose();
    qDebug()<<(modal3->rowCount());
}

void quanlyketquahoctap::on_bt_them_clicked()
{
    KhoaCNTT conn;
    QString Masv, Mamon,Tenmon,D1,D2,D3,Dt;
    Masv=ui->masv->currentText();
    Mamon=ui->mamon->text();
    Tenmon=ui->tenmon->text();
    D1=ui->diem1->text();
    D2=ui->diem2->text();
    D3=ui->diem3->text();
    Dt=ui->diemthi->text();
    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    if(Mamon==""||Tenmon=="")
    {
        QMessageBox::information(this,tr("Thông báo"),tr("Khong duoc de trong"));
    }
    else
    {
        qry.prepare("insert into QLketquahoctap (Masv,Mamon,Tenmon,D1,D2,D3,Dt) values ('"+Masv+"','"+Mamon+"','"+Tenmon+"','"+D1+"','"+D2+"','"+D3+"','"+Dt+"')");
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

void quanlyketquahoctap::on_bt_sua_clicked()
{
    KhoaCNTT conn;
    QString Masv, Mamon,Tenmon,D1,D2,D3,Dt;
    Mamon=ui->mamon->text();
    Tenmon=ui->tenmon->text();
    D1=ui->diem1->text();
    D2=ui->diem2->text();
    D3=ui->diem3->text();
    Dt=ui->diemthi->text();
    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    if(Mamon==""||Tenmon=="")
    {
        QMessageBox::information(this,tr("Thông báo"),tr("Khong duoc de trong"));
    }
    else
    {
        qry.prepare("update QLketquahoctap set Masv='"+Masv+"',Mamon='"+Mamon+"',Tenmon='"+Tenmon+"',D1='"+D1+"',D2='"+D2+"',D3='"+D3+"',Dt='"+Dt+"' where Mamon='"+Mamon+"' ");
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

void quanlyketquahoctap::on_bt_xoa_clicked()
{
    KhoaCNTT conn;
    QString Masv, Mamon,Tenmon,D1,D2,D3,Dt;
    Masv= ui->masv->currentText();

    Mamon=ui->mamon->text();

    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from QLketquahoctap  where Masv='"+Masv+"' and Mamon='"+Mamon+"' ");
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

void quanlyketquahoctap::on_bt_load_clicked()
{
    KhoaCNTT conn;
    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQueryModel * modal2= new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry= new QSqlQuery(conn.mydb);
    QSqlQuery* qry2= new QSqlQuery(conn.mydb);
    qry->prepare("select * from QLketquahoctap");
    qry2->prepare("select Masv from QLthongtin");
    qry->exec();
    qry2->exec();
    modal->setQuery(*qry);
    modal2->setQuery(*qry2);
    ui->masv->setModel(modal2);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
    qDebug()<<(modal2->rowCount());
}



void quanlyketquahoctap::on_bt_laydl_clicked()
{
    QString filename=QFileDialog::getOpenFileName(
                this,
                tr("Open FIle "),
                "C://",
                "All file(*.xlsx)"

                );

    QMessageBox::information(this,tr("File name"),filename);
    const wchar_t* ss;
    const wchar_t* s_msv;
    const wchar_t* s_mm;
    const wchar_t* s_tm;
    QString D1;
    QString D2;
    QString D3;
    QString Dt;
    QString masinhvien;
    QString mamon;
    QString tenmon;
    QString ab="d:\\phuc1.xlsx";
    QString sosanh;
   Book* book = xlCreateXMLBook();/// dinh dang cua xlsx
    if (book) {
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

                                s_mm = sheet->readStr(c, v+1);
                                std::wcout << std::endl;
                                wstring ws_mm(s_mm);
                                string str_mm(ws_mm.begin(), ws_mm.end());
                                mamon=str_mm.c_str();

                                s_tm = sheet->readStr(c, v+2);
                                std::wcout << std::endl;
                                wstring ws_tm(s_tm);
                                string str_tm(ws_tm.begin(), ws_tm.end());
                                tenmon=str_tm.c_str();

                                double d1 = sheet->readNum(c, v+3);
                                D1=QString::number(d1);
                                qDebug()<<D1;

                                double d2 = sheet->readNum(c, v+4);
                                D2=QString::number(d2);
                                qDebug()<<D2;

                                double d3 = sheet->readNum(c, v+5);
                                D3=QString::number(d3);
                                qDebug()<<D3;

                                double dt = sheet->readNum(c, v+6);
                                Dt=QString::number(dt);
                                qDebug()<<Dt;
                                //qry.prepare("insert into QLketquahoctap (Masv,Mamon,Tenmon,D1,D2,D3,Dt) values('"+masinhvien+"','"+mamon+"','"+tenmon+"','"+D1+"','"+D2+"','"+D3+"','"+Dt+"')");

                                //
                                 KhoaCNTT conn;

                                if(!conn.connOpen())
                                {
                                    qDebug()<<"Failed to open the database";
                                    return;
                                }

                                conn.connOpen();
                                QSqlQuery qry;


                                    qry.prepare("insert into QLketquahoctap (Masv,Mamon,Tenmon,D1,D2,D3,Dt) values ('"+masinhvien+"','"+mamon+"','"+tenmon+"','"+D1+"','"+D2+"','"+D3+"','"+Dt+"')");

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



void quanlyketquahoctap::on_pushButton_clicked()
{
    close();
}

void quanlyketquahoctap::on_tableView_activated(const QModelIndex &index)
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
         qry.prepare("select * from QLketquahoctap where Masv='"+val+"' or Mamon='"+val+"' or Tenmon='"+val+ "' or D1='"+val+"' or D2='"+val+"' or D3='"+val+"' or Dt='"+val+"'");
         if(qry.exec( ))
         {
            while(qry.next())
            {
               // ui->masv->setModel(qry.value(0).toString());

                 ui->mamon->setText(qry.value(1).toString());
                  ui->tenmon->setText(qry.value(2).toString());
                   ui->diem1->setText(qry.value(3).toString());
                    ui->diem2->setText(qry.value(4).toString());
                     ui->diem3->setText(qry.value(5).toString());
                      ui->diemthi->setText(qry.value(6).toString());
            }
             conn.connOpen();
         }
         else
         {
             QMessageBox::critical(this,tr("Error :"), qry.lastError().text());
         }

}

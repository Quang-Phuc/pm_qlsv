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

#ifdef _UNICODE
typedef wchar_t TCHAR;
#else
typedef char TCHAR;
#endif
#define LOG 1
#define LOG_H qDebug() << "[High]"
#define LOG_M qDebug() << "[Medium]"
#define LOG_L qDebug() << "[Low]"
using namespace libxl;
using namespace std;
themlophoc::themlophoc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::themlophoc)
{
    ui->setupUi(this);
 //   QPixmap pix("D:\3\aaaa.jpg");
  //  ui->label_anh->setPixmap(pix);
    KhoaCNTT conn;
    if(!conn.connOpen())
        ui->tinhtrang->setText("Faile to open the database");
    else
        ui->tinhtrang->setText("Connetcted...");
}

themlophoc::~themlophoc()
{
    delete ui;
}





void themlophoc::on_pushButton_4_clicked()
{
    KhoaCNTT conn;
    QSqlQueryModel * modal= new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry= new QSqlQuery(conn.mydb);
    qry->prepare("select * from QLlophoc");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
}

void themlophoc::on_bu_timkiem_clicked()
{
    KhoaCNTT conn;
    QString timkiem;
    timkiem=ui->timkiem3->text();
    QSqlQueryModel * modal= new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry= new QSqlQuery(conn.mydb);
    qry->prepare("select * from QLlophoc where Malop='"+timkiem+"'");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
}






void themlophoc::on_bt_them_clicked()
{
    KhoaCNTT conn;
      QString Malop, Tenlop,Soluongsv,Mota;
      Malop=ui->malop->text();
      Tenlop=ui->tenlop->text();
      Soluongsv=ui->soluong->text();
      Mota=ui->mota->text();

      if(!conn.connOpen())
      {
          qDebug()<<"Failed to open the database";
          return;



      }

      conn.connOpen();
      QSqlQuery qry;
      if(Malop==""||Tenlop==""||Soluongsv=="")
      {
          QMessageBox::information(this,tr("Thông báo"),tr("Khong duoc de trong"));
      }
      else
      {
      qry.prepare("insert into QLlophoc (Malop,Tenlop,Soluongsv,Mota) values ('"+Malop+"','"+Tenlop+"','"+Soluongsv+"','"+Mota+"')");
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

void themlophoc::on_bt_laydl_clicked()
{
    QString filename=QFileDialog::getOpenFileName(
                this,
                tr("Open FIle "),
                "C://",
                "All file(*.*);;Text File(*.txt)"

                );
    QMessageBox::information(this,tr("File name"),filename);
       qDebug()<<filename;
    const wchar_t* ss;
    const wchar_t* s_ml;
    const wchar_t* s_tl;
    const wchar_t* s_mt;
    QString D;
    QString malop;
    QString tenlop;
    QString mota;
    QString sosanh;
    Book* book = xlCreateXMLBook();// dinh dang cua xlsx
    if (book) {

        // char*param=new char[filename.size()+1];
         //L"D:/phuc.xlsx"

              // TCHAR *param=new TCHAR[str.c_str()];
             //  TCHAR *p= str.c_str();
              // (const TCHAR*)str.c_str();
             //   qDebug()<<str;
              //  param[str.size()]=0;
               // std::copy(str.begin(),str.end(),param);
              //    qDebug()<<param;
              //  USES_CONVERSION;
             //  TCHAR* directory = A2T(data);
               //(const TCHAR*)str.c_str())
          std::string str = filename.toStdString();
        wstring a(str.begin(),str.end());
       const wchar_t* phuc = a.c_str();
        if(book->load(phuc)) {
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

                        if(sosanh=="Malop")
                        {
                            int b=row;
                            int v=col;

                            for(int c= b+1; c < sheet->lastRow(); ++c)
                            {
                                s_ml = sheet->readStr(c, v);
                                wstring ws_ml(s_ml);
                                string str_ml(ws_ml.begin(), ws_ml.end());
                                malop=str_ml.c_str();
                                std::wcout << std::endl;

                                s_tl = sheet->readStr(c, v+1);
                                std::wcout << std::endl;
                                wstring ws_tl(s_tl);
                                string str_tl(ws_tl.begin(), ws_tl.end());
                                tenlop=str_tl.c_str();

                                double d = sheet->readNum(c, v+2);
                                D=QString::number(d);
                                qDebug()<<D;
                                s_mt = sheet->readStr(c, v+3);
                                std::wcout << std::endl;
                                wstring ws_mt(s_mt);
                                string str_mt(ws_mt.begin(), ws_mt.end());
                                mota=str_mt.c_str();

                                KhoaCNTT conn;


                                if(!conn.connOpen())
                                {
                                    qDebug()<<"Failed to open the database";
                                    return;


                                }

                                conn.connOpen();
                                QSqlQuery qry;
                                if(malop==""||tenlop==""||mota=="")
                                {
                                    QMessageBox::information(this,tr("Thông báo"),tr("Chưa lấy được dữ liệu"));
                                }
                                else
                                {
                                qry.prepare("insert into QLlophoc (Malop,Tenlop,Soluongsv,Mota) values ('"+malop+"','"+tenlop+"','"+D+"','"+mota+"')");
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
                        }
                    }
                }

            }
        }
    }

    book->release();
}

void themlophoc::on_bt_xoa_clicked()
{
    KhoaCNTT conn;
    QString Malop;
    Malop=ui->malop->text();
    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from QLlophoc  where Malop='"+Malop+"'");
    if(qry.exec( ))
    {

        QMessageBox::information(this,tr("Thông báo"),tr("xóa thành công thông tin thành công"));
        conn.connClose();

    }
    else
    {
        QMessageBox::information(this,tr("Lỗi "),qry.lastError().text());
    }
}

void themlophoc::on_bt_sua_clicked()
{
    KhoaCNTT conn;
    QString Malop, Tenlop,Soluongsv,Mota;
    Malop=ui->malop->text();
    Tenlop=ui->tenlop->text();
    Soluongsv=ui->soluong->text();
    Mota=ui->mota->text();

    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    if(Malop==""||Tenlop==""||Soluongsv=="")
    {
        QMessageBox::information(this,tr("Thông báo"),tr("Khong duoc de trong"));
    }
    else
    {
        qry.prepare("update QLlophoc set Malop='"+Malop+"',Tenlop='"+Tenlop+"',Soluongsv='"+Soluongsv+"',Mota='"+Mota+"' where Malop='"+Malop+"' ");
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



void themlophoc::on_openfile_clicked()
{



}

void themlophoc::on_tableView_activated(const QModelIndex &index)
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
         qry.prepare("select * from QLlophoc where Malop='"+val+"' or Tenlop='"+val+"' or Soluongsv='"+val+ "' or Mota='"+val+"'");
         if(qry.exec( ))
         {
            while(qry.next())
            {
                ui->malop->setText(qry.value(0).toString());
                 ui->tenlop->setText(qry.value(1).toString());
                  ui->soluong->setText(qry.value(2).toString());
                   ui->mota->setText(qry.value(3).toString());
            }
             conn.connOpen();
         }
         else
         {
             QMessageBox::critical(this,tr("Error :"), qry.lastError().text());
         }

}

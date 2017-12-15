#include "khoacntt.h"
#include "ui_khoacntt.h"
#include <QMessageBox>
#include "menudialog.h"
#include "khoacntt.h"
#include "dangky.h"
#include "quenmatkhau.h"
#include <QMediaPlayer>
#include <QFileDialog>

KhoaCNTT::KhoaCNTT(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KhoaCNTT)
{
    ui->setupUi(this);
   // mMediaPlayer = new QMediaPlayer;
  //8  connect(mMediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
   //8 mMediaPlayer->setMedia();
   // mMediaPlayer->setMedia(QUrl::fromLocalFile("D:\modau.mp3"));
  //  mMediaPlayer->setVolume(50);
  //  mMediaPlayer->play();

  //  d:\\phuc2.xlsx
 //   QPixmap pix("D:\3\image.png");

  //  ui->label_image->setPixmap(pix);
  //  ui->anh2->setStyleSheet("background-image: url(:D:\nha.jpg);");
   // QImage image("D:\nha.jpg");
       //ui->anh2->setPixmap(QPixmap::fromImage(image));
    if(!connOpen())
        ui->thongbao->setText("Faile to open the database");
    else
        ui->thongbao->setText("Connetcted...");
}
KhoaCNTT::~KhoaCNTT()
{
    delete ui;
}
void KhoaCNTT::on_bt_dangnhap_clicked()

{
    // mMediaPlayer->stop();
    QString TaiKhoan, Matkhau;
    TaiKhoan=ui->taikhoan->text();
    Matkhau=ui->matkhau->text();
    if(!connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    QSqlQuery qry;
    qry.prepare("select * from Dangnhap where TaiKhoan='"+TaiKhoan +"'and Matkhau='"+Matkhau+"'");
    if(qry.exec( ))
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            ui->thongbao->setText("Dang nhap thanh cong");
            connClose();
            this->hide();
            menuDialog menudialog;
            menudialog.setModal(true);
            menudialog.exec();
        }
        if(count>1)
        {ui->label->setText("Duplicate Taikhoan va mat khau");}
        if(count<1)
        {  QMessageBox::information(this,tr("Thông báo"),tr("Bạn đã nhập sai"));}
    }
}
void KhoaCNTT::on_bt_thoat_clicked()
{
   close();
}

void KhoaCNTT::on_label_5_linkActivated(const QString &link)
{
     //link="https://www.haui.edu.vn/vn";
  //  QDesktopServices::openUrl(QUrl(link));
}

void KhoaCNTT::on_dangky_clicked()
{
    Dangky dk;
    dk.setModal(true);
    dk.exec();

}

void KhoaCNTT::on_quenmk_clicked()
{
    Quenmatkhau quenmk;
    quenmk.setModal(true);
    quenmk.exec();
}

void KhoaCNTT::on_KhoaCNTT_destroyed()
{

}

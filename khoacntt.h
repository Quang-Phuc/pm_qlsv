#ifndef KHOACNTT_H
#define KHOACNTT_H

#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

namespace Ui {
class KhoaCNTT;
}
//class QMediaPlayer;
class KhoaCNTT : public QWidget
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
{
        mydb=QSqlDatabase ::addDatabase("QSQLITE");
       mydb.setDatabaseName("E:/Cau_Phan/Quanlysinhvien.sqlite");
       if(!mydb.open())
          { qDebug()<<("Faile to open the database");
          return false;
       }
       else
           qDebug()<<("Connetcted...");
           return true;
}

public:
    explicit KhoaCNTT(QWidget *parent = 0);
    ~KhoaCNTT();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_bt_dangnhap_clicked();

    void on_bt_thoat_clicked();

    void on_label_image_linkActivated(const QString &link);

    void on_label_5_linkActivated(const QString &link);

    void on_dangky_clicked();

    void on_quenmk_clicked();

    void on_KhoaCNTT_destroyed();

private:
    Ui::KhoaCNTT *ui;
  //  QMediaPlayer *mMediaPlayer;

};

#endif // KHOACNTT_H

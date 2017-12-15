#ifndef MENUDIALOG_H
#define MENUDIALOG_H

#include <QDialog>

namespace Ui {
class menuDialog;
}
class QMediaPlayer;
class menuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit menuDialog(QWidget *parent = 0);
    ~menuDialog();

private slots:

    void on_trangchu_clicked();

    void on_quanlythongtin_clicked();

    void on_quanlyketquahoctap_clicked();

    void on_quanlythongtinlophoc_clicked();

    void on_hoso_clicked();

    void on_thoat_clicked();

private:
    Ui::menuDialog *ui;
     QMediaPlayer *mMediaPlayer;
};

#endif // MENUDIALOG_H

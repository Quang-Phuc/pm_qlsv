#ifndef QUANLYKETQUAHOCTAP_H
#define QUANLYKETQUAHOCTAP_H

#include <QDialog>

namespace Ui {
class quanlyketquahoctap;
}

class quanlyketquahoctap : public QDialog
{
    Q_OBJECT

public:
    explicit quanlyketquahoctap(QWidget *parent = 0);
    ~quanlyketquahoctap();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_Timkiem_clicked();

    void on_bt_them_clicked();

    void on_bt_sua_clicked();

    void on_bt_xoa_clicked();

    void on_bt_load_clicked();

    void on_bt_laydl_clicked();

    void on_buttonBox_accepted();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::quanlyketquahoctap *ui;
};

#endif // QUANLYKETQUAHOCTAP_H

#ifndef THEMLOPHOC_H
#define THEMLOPHOC_H

#include <QDialog>

namespace Ui {
class themlophoc;
}

class themlophoc : public QDialog
{
    Q_OBJECT

public:
    explicit themlophoc(QWidget *parent = 0);
    ~themlophoc();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_bu_timkiem_clicked();

    void on_demo_clicked();

    void on_demo_clicked(bool checked);

    void on_bt_them_clicked();

    void on_bt_sua_clicked();

    void on_bt_xoa_clicked();

    void on_bt_laydl_clicked();

    void on_openfile_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::themlophoc *ui;
};

#endif // THEMLOPHOC_H

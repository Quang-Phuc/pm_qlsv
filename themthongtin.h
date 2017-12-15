#ifndef THEMTHONGTIN_H
#define THEMTHONGTIN_H

#include <QDialog>
#include "khoacntt.h"

namespace Ui {
class themthongtin;
}

class themthongtin : public QDialog
{
    Q_OBJECT

public:

    explicit themthongtin(QWidget *parent = 0);
    ~themthongtin();

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_Load_clicked();

    void on_timkiem_clicked();

    void on_bt_sua_clicked();

    void on_bt_xoa_clicked();

    void on_bt_them_clicked();

    void on_bt_laydl_clicked();

    void on_label_windowTitleChanged(const QString &title);

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::themthongtin *ui;
};

#endif // THEMTHONGTIN_H

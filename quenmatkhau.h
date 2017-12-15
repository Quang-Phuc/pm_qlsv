#ifndef QUENMATKHAU_H
#define QUENMATKHAU_H

#include <QDialog>

namespace Ui {
class Quenmatkhau;
}

class Quenmatkhau : public QDialog
{
    Q_OBJECT

public:
    explicit Quenmatkhau(QWidget *parent = 0);
    ~Quenmatkhau();

private slots:
    void on_timmatkhau_clicked();

    void on_doimatkhau_clicked();

    void on_thoat_clicked();

private:
    Ui::Quenmatkhau *ui;
};

#endif // QUENMATKHAU_H

#ifndef DOIMATKHAU_H
#define DOIMATKHAU_H

#include <QDialog>

namespace Ui {
class Doimatkhau;
}

class Doimatkhau : public QDialog
{
    Q_OBJECT

public:
    explicit Doimatkhau(QWidget *parent = 0);
    ~Doimatkhau();

private slots:
    void on_thaydoi_clicked();

    void on_thoat_clicked();

private:
    Ui::Doimatkhau *ui;
};

#endif // DOIMATKHAU_H

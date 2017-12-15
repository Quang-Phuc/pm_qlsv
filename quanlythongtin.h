#ifndef QUANLYTHONGTIN_H
#define QUANLYTHONGTIN_H

#include <QDialog>

namespace Ui {
class quanlythongtin;
}

class quanlythongtin : public QDialog
{
    Q_OBJECT

public:
    explicit quanlythongtin(QWidget *parent = 0);
    ~quanlythongtin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::quanlythongtin *ui;
};

#endif // QUANLYTHONGTIN_H

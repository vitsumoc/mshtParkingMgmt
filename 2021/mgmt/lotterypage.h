#ifndef LOTTERYPAGE_H
#define LOTTERYPAGE_H

#include <QWidget>
#include <QMutex>

namespace Ui {
class LotteryPage;
}

class QTimer;
class Owner;

class LotteryPage : public QWidget
{
    Q_OBJECT

public:
    explicit LotteryPage(QWidget *parent = nullptr);
    ~LotteryPage();

    void changeRound();

protected:
    void paintEvent(QPaintEvent *e) override;

private slots:
    void on_btn_lottery_clicked();

    void slt_timer();

private:
    Ui::LotteryPage *ui;

    QTimer *_timer;
    bool _rolling = false;

    Owner *_owner;
    bool _ownerWin = false;
    void doRoll();

    // 摇号和入库的互斥量
    QMutex _mutex;
};

#endif // LOTTERYPAGE_H

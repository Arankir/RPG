#ifndef PROGRESSBARHP_H
#define PROGRESSBARHP_H
#include <QProgressBar>

class ProgressBarHp : public QProgressBar {
    Q_OBJECT
public:
    ProgressBarHp(QWidget *parent): QProgressBar(parent) {};
};

#endif // PROGRESSBARHP_H

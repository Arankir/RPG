#ifndef PROGRESSBARMP_H
#define PROGRESSBARMP_H
#include <QProgressBar>

class ProgressBarMp : public QProgressBar {
    Q_OBJECT
public:
    ProgressBarMp(QWidget *parent): QProgressBar(parent) {};
};

#endif // PROGRESSBARMP_H

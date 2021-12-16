#ifndef PROGRESSBAREXP_H
#define PROGRESSBAREXP_H
#include <QProgressBar>

class ProgressBarExp : public QProgressBar {
    Q_OBJECT
public:
    ProgressBarExp(QWidget *parent): QProgressBar(parent) {};
};

#endif // PROGRESSBAREXP_H

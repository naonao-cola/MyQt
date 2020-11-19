#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QLabel>
#include <QTextEdit>
#include <QImage>

#include <QWidget>
#include "clickablelabel.h"
class ShowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ShowWidget(QWidget *parent = nullptr);

    QImage img;
    ClickableLabel *imageLabel;
    QTextEdit *text;
signals:

public slots:
};

#endif // SHOWWIDGET_H

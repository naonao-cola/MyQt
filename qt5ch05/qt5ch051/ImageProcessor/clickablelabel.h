#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QImage>
class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickableLabel( const QString& text="", QWidget* parent=0 );
    ~ClickableLabel();
     QImage img;
signals:
    void clicked();
protected :
  void mousePressEvent(QMouseEvent* event);
public:

};

#endif // CLICKABLELABEL_H

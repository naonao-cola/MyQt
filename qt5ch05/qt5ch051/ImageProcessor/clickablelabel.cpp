#include "clickablelabel.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QFileDialog>
#include <QImage>
ClickableLabel::ClickableLabel(const QString& text, QWidget* parent)
    : QLabel(parent)
{
    setText(text);
}

ClickableLabel::~ClickableLabel()
{

}
void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
    if(event->button()== Qt::LeftButton)
    {
//        QMessageBox::information(NULL,"单击","单击了我",
//                                 QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);


        QString filepath = QFileDialog::getOpenFileName(this);
        if (!filepath.isEmpty())
        {
            if(img.load(filepath))
            {
                //设置图片，在image中放置图片
                this->setPixmap(QPixmap::fromImage(img));
            }
            //QMessageBox::warning(NULL, "提示", "未选择数据文件", "确定");

        }

    }

    QLabel::mousePressEvent(event);
    return;
}


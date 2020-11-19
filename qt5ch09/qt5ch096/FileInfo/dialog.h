#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0,Qt::WindowFlags f=0);
    ~Dialog();
public slots:
    void slotFile();
    void slotGet();
private:
    QLabel *fileNameLabel;
    QLineEdit *fileNameLineEdit;
    QPushButton *fileBtn;
    QLabel *sizeLabel;
    QLineEdit *sizeLineEdit;

    QLabel *createTimeLabel;
    QLineEdit *createTimeLineEdit;

    QLabel *lastModifiedLabel;
    QLineEdit *lastModifiedLineEdit;

    QLabel *lastReadLabel;
    QLineEdit *lastReadLineEdit;

    QLabel *propertyLabel;

    QCheckBox *isDirCheckBox;
    QCheckBox *isFileCheckBox;
    QCheckBox *isSymLinkCheckBox;
    QCheckBox *isHiddenCheckBox;
    QCheckBox *isReadableCheckBox;
    QCheckBox *isWritableCheckBox;
    QCheckBox *isExecutableCheckBox;

    QPushButton *getBtn;


};

#endif // DIALOG_H

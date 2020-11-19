#ifndef LANGSWITCH_H
#define LANGSWITCH_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
class LangSwitch : public QWidget
{
    Q_OBJECT

public:
    LangSwitch(QWidget *parent = 0);
    ~LangSwitch();

private slots:
    //下拉菜单语言选项的改变
    void changeLang(int index);

private:
    void createScreen();
    void changeTr(const QString& langCode);
    void refreshLabel();

    QComboBox* combo;
    QLabel *label;
};

#endif // LANGSWITCH_H

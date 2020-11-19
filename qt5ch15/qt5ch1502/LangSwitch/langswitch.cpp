#include "langswitch.h"
#include <QVBoxLayout>
#include <QTranslator>
#include <QApplication>

LangSwitch::LangSwitch(QWidget *parent)
    : QWidget(parent)
{
    //创建基本界面
    createScreen();
}

LangSwitch::~LangSwitch()
{

}

void LangSwitch::createScreen()
{
    combo = new QComboBox;
    combo->addItem("English", "en");			//(a)
    combo->addItem("Chinese", "zh");
    combo->addItem("Latin", "la");
    label = new QLabel;
    refreshLabel();								//设置标签的内容
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(combo, 1);
    layout->addWidget(label, 5);
    setLayout(layout);
    connect(combo, SIGNAL(currentIndexChanged(int)),
          this, SLOT(changeLang(int)));			//(b)
}


void LangSwitch::refreshLabel()
{
      label->setText(tr("TXT_HELLO_WORLD", "Hello World"));		//(a)
}


void LangSwitch::changeLang(int index)
{
      QString langCode = combo->itemData(index).toString();		//(a)
      changeTr(langCode);		//读取相应的“.qm”文件
      refreshLabel();			//刷新标签上的文字
}


void LangSwitch::changeTr(const QString& langCode)
{
    static QTranslator* translator;								//(a)
    if (translator != NULL)
    {
        qApp->removeTranslator(translator);
        delete translator;
        translator = NULL;
    }
    translator = new QTranslator;
    QString qmFilename = "lang_" + langCode;					//(b)
    if (translator->load(QString("I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch15/qt5ch1502/LangSwitch")+
                         qmFilename))
    {
        qApp->installTranslator(translator);
    }
}

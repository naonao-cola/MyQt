#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMainWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainWindow()
{
    //加载系统标准字号集
    QFontDatabase fontdb;
    foreach(int fontsize,fontdb.standardSizes())
        ui->sizeComboBox->addItem(QString::number(fontsize));
    ui->sizeComboBox->setCurrentIndex(ui->sizeComboBox->findText(QString::number(QApplication::font().pointSize())));
    //多文档区域设置
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    refreshMenus();
    //当有活动文档子窗口时刷新菜单
    connect(ui->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(refreshMenus()));

    //添加子窗口菜单项列表
    myWndMapper = new QSignalMapper(this);//创建信号映射器
    connect(myWndMapper, SIGNAL(mapped(QWidget*)), this, SLOT(setActiveSubWindow(QWidget*)));
    addSubWndListMenu();
    connect(ui->menu_W, SIGNAL(aboutToShow()), this, SLOT(addSubWndListMenu()));

    //将【段落】菜单下的各对齐方式功能项加入同一个菜单项组，这样程序运行的任一时刻用户能且只能选中其中一项
    QActionGroup *alignGroup = new QActionGroup(this);
    alignGroup->addAction(ui->leftAlignAction);
    alignGroup->addAction(ui->centerAction);
    alignGroup->addAction(ui->rightAlignAction);
    alignGroup->addAction(ui->justifyAction);
    ui->leftAlignAction->setChecked(true);
}

//新建文档
void MainWindow::docNew()
{
    MyChildWnd *childWnd = new MyChildWnd;         //创建mychildwnd部件
    //向多文档区域添加子窗口，childwnd为中心部件
    ui->mdiArea->addSubWindow(childWnd);
    //根据QTextEdit类是否可以复制信号，设置剪切、复制动作是否可用
    connect(childWnd,SIGNAL(copyAvailable(bool)),ui->cutAction,SLOT(setEnabled(bool)));
    connect(childWnd, SIGNAL(copyAvailable(bool)), ui->copyAction, SLOT(setEnabled(bool)));

    childWnd->newDoc();
    childWnd->show();
    //使格式菜单下各功能项变为可用
    formatEnabled();

}

void MainWindow::docOpen()
{
    QString docName = QFileDialog::getOpenFileName(this, tr("打开"), QString(), tr("HTML 文档 (*.htm *.html);;所有文件 (*.*)"));
    if (!docName.isEmpty())
    {
        QMdiSubWindow *exist = findChildWnd(docName);
        if (exist)
        {
            ui->mdiArea->setActiveSubWindow(exist);
            return;
        }
        MyChildWnd *childwnd = new MyChildWnd;
        ui->mdiArea->addSubWindow(childwnd);
        connect(childwnd, SIGNAL(copyAvailable(bool)), ui->cutAction, SLOT(setEnabled(bool)));
        connect(childwnd, SIGNAL(copyAvailable(bool)), ui->copyAction, SLOT(setEnabled(bool)));
        if (childwnd->loadDoc(docName))
        {
            statusBar()->showMessage(tr("文档已打开"), 2000);
            childwnd->show();
            formatEnabled();//使【字体】菜单下的功能可用
        } else {
            childwnd->close();
        }
    }
}

void MainWindow::docSave()
{
    if (activateChildWnd() && activateChildWnd()->saveDoc())
        statusBar()->showMessage(tr("保存成功"), 2000);
}

void MainWindow::docSaveAs()
{
    if (activateChildWnd() && activateChildWnd()->saveAsDoc())
        statusBar()->showMessage(tr("保存成功"), 2000);
}

void MainWindow::docUndo()
{
    if (activateChildWnd()) activateChildWnd()->undo();
}

void MainWindow::docRedo()
{
    if (activateChildWnd()) activateChildWnd()->redo();
}

void MainWindow::docCut()
{
    if (activateChildWnd()) activateChildWnd()->cut();
}

void MainWindow::docCopy()
{
    if (activateChildWnd()) activateChildWnd()->copy();
}

void MainWindow::docPaste()
{
    if (activateChildWnd()) activateChildWnd()->paste();
}

void MainWindow::textBold()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(ui->boldAction->isChecked() ? QFont::Bold : QFont::Normal);
    if(activateChildWnd()) activateChildWnd()->setFormatOnSelectedWord(fmt);
}

void MainWindow::textItalic()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(ui->italicAction->isChecked());
    if(activateChildWnd()) activateChildWnd()->setFormatOnSelectedWord(fmt);
}

void MainWindow::textUnderline()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(ui->underlineAction->isChecked());
    if(activateChildWnd()) activateChildWnd()->setFormatOnSelectedWord(fmt);
}

void MainWindow::textFamily(const QString &fmly)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(fmly);
    if(activateChildWnd()) activateChildWnd()->setFormatOnSelectedWord(fmt);
}

void MainWindow::textSize(const QString &ps)
{
    qreal pointSize = ps.toFloat();
    if (ps.toFloat() > 0)
    {
        QTextCharFormat fmt;
        fmt.setFontPointSize(pointSize);
        if(activateChildWnd()) activateChildWnd()->setFormatOnSelectedWord(fmt);
    }
}

void MainWindow::textAlign(QAction *act)
{
    if (activateChildWnd())
    {
        if (act == ui->leftAlignAction) activateChildWnd()->setAlignOfDocumentText(1);
        else if (act == ui->centerAction) activateChildWnd()->setAlignOfDocumentText(2);
        else if (act == ui->rightAlignAction) activateChildWnd()->setAlignOfDocumentText(3);
        else if (act == ui->justifyAction) activateChildWnd()->setAlignOfDocumentText(4);
    }
}

void MainWindow::textColor()
{
    if (activateChildWnd())
    {
        QColor color = QColorDialog::getColor(activateChildWnd()->textColor(), this);
        if (!color.isValid()) return;
        QTextCharFormat fmt;
        fmt.setForeground(color);
        activateChildWnd()->setFormatOnSelectedWord(fmt);
        QPixmap pix(16, 16);
        pix.fill(color);
        ui->colorAction->setIcon(pix);
    }
}

void MainWindow::paraStyle(int sidx)
{
    if (activateChildWnd()) activateChildWnd()->setParaStyle(sidx);
}

void MainWindow::docPrint()
{
    QPrinter pter(QPrinter::HighResolution);
    QPrintDialog *pdlg = new QPrintDialog(&pter, this);
    if (activateChildWnd()->textCursor().hasSelection())
        pdlg->addEnabledOption(QAbstractPrintDialog::PrintSelection);
    pdlg->setWindowTitle(tr("打印文档"));
    if (pdlg->exec() == QDialog::Accepted)
        activateChildWnd()->print(&pter);
    delete pdlg;
}

void MainWindow::docPrintPreview()
{
    QPrinter pter(QPrinter::HighResolution);
    QPrintPreviewDialog pview(&pter, this);
    connect(&pview, SIGNAL(paintRequested(QPrinter*)), SLOT(printPreview(QPrinter*)));
    pview.exec();
}

void MainWindow::printPreview(QPrinter*pter)
{
    activateChildWnd()->print(pter);
}

void MainWindow::on_aboutAction_triggered()
{
    QMessageBox::about(this,tr("关于"),tr("这是一个基于Qt5实现的字处理软件\r\n"
                                        "具备类似微软office word功能"));
}

void MainWindow::on_aboutQtAction_triggered()
{
    QMessageBox::aboutQt(nullptr,"关于Qt 5");
}

void MainWindow::on_newAction_triggered()
{
    docNew();
}

void MainWindow::refreshMenus()
{
    //至少有一个文档子窗口打开的情况
    bool hasChild = (activateChildWnd() != nullptr);
    ui->saveAction->setEnabled(hasChild);
    ui->saveAsAction->setEnabled(hasChild);
    ui->printAction->setEnabled(hasChild);
    ui->printPreviewAction->setEnabled(hasChild);
    ui->pasteAction->setEnabled(hasChild);
    ui->closeAction->setEnabled(hasChild);
    ui->closeAllAction->setEnabled(hasChild);
    ui->tileAction->setEnabled(hasChild);
    ui->cascadeAction->setEnabled(hasChild);
    ui->nextAction->setEnabled(hasChild);
    ui->previousAction->setEnabled(hasChild);
    //文档已打开并且其中有内容被选中的情况
    bool hasSelect = (activateChildWnd() && activateChildWnd()->textCursor().hasSelection());
    ui->cutAction->setEnabled(hasSelect);
    ui->copyAction->setEnabled(hasSelect);
    ui->boldAction->setEnabled(hasSelect);
    ui->italicAction->setEnabled(hasSelect);
    ui->underlineAction->setEnabled(hasSelect);
    ui->leftAlignAction->setEnabled(hasSelect);
    ui->centerAction->setEnabled(hasSelect);
    ui->rightAlignAction->setEnabled(hasSelect);
    ui->justifyAction->setEnabled(hasSelect);
    ui->colorAction->setEnabled(hasSelect);
}

void MainWindow::addSubWndListMenu()
{
    //首先清空原【窗口】菜单，然后再添加各菜单项
    ui->menu_W->clear();
    ui->menu_W->addAction(ui->closeAction);
    ui->menu_W->addAction(ui->closeAllAction);
    ui->menu_W->addSeparator();
    ui->menu_W->addAction(ui->tileAction);
    ui->menu_W->addAction(ui->cascadeAction);
    ui->menu_W->addSeparator();
    ui->menu_W->addAction(ui->nextAction);
    ui->menu_W->addAction(ui->previousAction);
    QList<QMdiSubWindow *> wnds = ui->mdiArea->subWindowList();
    if (!wnds.isEmpty()) ui->menu_W->addSeparator();//如果有活动子窗口，显示分隔条
    //遍历各个子窗口，显示所有当前已打开的文档子窗口项
    for (int i = 0; i < wnds.size(); ++i)
    {
        MyChildWnd *childwnd = qobject_cast<MyChildWnd *>(wnds.at(i)->widget());
        QString menuitem_text;
        if (i < 9)
        {
            menuitem_text = tr("&%1 %2").arg(i + 1).arg(childwnd->getCurDocName());
        } else {
            menuitem_text = tr("%1 %2").arg(i + 1).arg(childwnd->getCurDocName());
        }
        //添加子窗口菜单项，设置其可选
        QAction *menuitem_act = ui->menu_W->addAction(menuitem_text);
        menuitem_act->setCheckable(true);
        //将当前活动的子窗口设为勾选状态
        menuitem_act->setChecked(childwnd == activateChildWnd());
        //关联菜单项的触发信号到信号映射器的map()槽，该槽会发送mapped()信号
        connect(menuitem_act, SIGNAL(triggered()), myWndMapper, SLOT(map()));
        //将菜单项与相应的窗口部件进行映射，在发送mapped()信号时就会以这个窗口部件为参数
        myWndMapper->setMapping(menuitem_act, wnds.at(i));
    }
    formatEnabled();//使【字体】菜单下的功能可用
}

void MainWindow::setActiveSubWindow(QWidget *wnd)
{
    if (!wnd) return;
    ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(wnd));
}

void MainWindow::on_openAction_triggered()
{
    docOpen();
}

void MainWindow::on_saveAction_triggered()
{
    docSave();
}

void MainWindow::on_saveAsAction_triggered()
{
    docSaveAs();
}

void MainWindow::on_undoAction_triggered()
{
    docUndo();
}

void MainWindow::on_redoAction_triggered()
{
    docRedo();
}

void MainWindow::on_cutAction_triggered()
{
    docCut();
}

void MainWindow::on_copyAction_triggered()
{
    docCopy();
}

void MainWindow::on_pasteAction_triggered()
{
    docPaste();
}

void MainWindow::on_boldAction_triggered()
{
    textBold();
}

void MainWindow::on_italicAction_triggered()
{
    textItalic();
}

void MainWindow::on_underlineAction_triggered()
{
    textUnderline();
}

void MainWindow::on_leftAlignAction_triggered()
{
    textAlign(ui->leftAlignAction);
}

void MainWindow::on_centerAction_triggered()
{
    textAlign(ui->centerAction);
}

void MainWindow::on_rightAlignAction_triggered()
{
    textAlign(ui->rightAlignAction);
}

void MainWindow::on_justifyAction_triggered()
{
    textAlign(ui->justifyAction);
}

void MainWindow::on_colorAction_triggered()
{
    textColor();
}

void MainWindow::on_closeAction_triggered()
{
    ui->mdiArea->closeActiveSubWindow();
}

void MainWindow::on_closeAllAction_triggered()
{
    ui->mdiArea->closeAllSubWindows();
}

void MainWindow::on_tileAction_triggered()
{
    //窗口平铺
    ui->mdiArea->tileSubWindows();
}

void MainWindow::on_cascadeAction_triggered()
{
    //窗口层叠
    ui->mdiArea->cascadeSubWindows();
}

void MainWindow::on_nextAction_triggered()
{
    //下一个窗口
    ui->mdiArea->activateNextSubWindow();
}

void MainWindow::on_previousAction_triggered()
{
    //前一个窗口
    ui->mdiArea->activatePreviousSubWindow();
}

//关闭事件
void MainWindow::closeEvent(QCloseEvent *event)
{
    ui->mdiArea->closeAllSubWindows();
    if (ui->mdiArea->currentSubWindow())
    {
        event->ignore();
    } else {
        event->accept();
    }
}
//使格式菜单及其工具按钮可用
void MainWindow::formatEnabled()
{
    ui->boldAction->setEnabled(true);
    ui->italicAction->setEnabled(true);
    ui->underlineAction->setEnabled(true);
    ui->leftAlignAction->setEnabled(true);
    ui->centerAction->setEnabled(true);
    ui->rightAlignAction->setEnabled(true);
    ui->justifyAction->setEnabled(true);
    ui->colorAction->setEnabled(true);
}

MyChildWnd *MainWindow::activateChildWnd()
{
    //若有活动文档窗口，则将其内的中心部件转换为MyChildWnd类型；若没有，则直接返回0
    if (QMdiSubWindow *actSubWnd = ui->mdiArea->activeSubWindow())
        return qobject_cast<MyChildWnd *>(actSubWnd->widget());
    else
        return nullptr;
}

QMdiSubWindow *MainWindow::findChildWnd(const QString &docName)
{
    QString canonicalFilePath = QFileInfo(docName).canonicalFilePath();
    foreach (QMdiSubWindow *wnd, ui->mdiArea->subWindowList())
    {
        MyChildWnd *childwnd = qobject_cast<MyChildWnd *>(wnd->widget());
        if (childwnd->myCurDocPath == canonicalFilePath) return wnd;
    }
    return 0;
}

void MainWindow::on_fontComboBox_activated(const QString &arg1)
{
    textFamily(arg1);
}

void MainWindow::on_sizeComboBox_activated(const QString &arg1)
{
    textSize(arg1);
}

void MainWindow::on_styleComboBox_activated(int index)
{
    paraStyle(index);
}

void MainWindow::on_printAction_triggered()
{
    docPrint();
}

void MainWindow::on_printPreviewAction_triggered()
{
    docPrintPreview();
}

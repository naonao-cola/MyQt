#ifndef HISTOGRAMVIEW_H
#define HISTOGRAMVIEW_H

#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QRegion>
#include <QMouseEvent>

class HistogramView : public QAbstractItemView
{
    Q_OBJECT
public:
    HistogramView(QWidget *parent = nullptr);

    //虚函数声明
    QRect visualRect(const QModelIndex &index) const;
    void scrollTo(const QModelIndex &index,ScrollHint hint =EnsureVisible);
    //鼠标点击或位置改变是，返回Index
    QModelIndex indexAt(const QPoint &point) const;

    //selection初值
    void setSelectionModel(QItemSelectionModel *selectionModel);
    QRegion itemRegion(QModelIndex index);
    void paintEvent(QPaintEvent *);
    //柱状图选择后以不同的方式显示
    void mousePressEvent(QMouseEvent *event);
//槽函数
protected slots:
    //数据项变化时，槽函数响应
    void selectionChanged(const QItemSelection &selected,const QItemSelection &deselected);
    //模型中数据改变时，槽函数响应
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int>());


protected:
    //虚函数
    QModelIndex moveCursor(QAbstractItemView::CursorAction cursorAction,
                           Qt::KeyboardModifiers modifiers);
    int horizontalOffset() const;
    int verticalOffset() const;
    bool isIndexHidden(const QModelIndex &Index) const;
    //将位于rect的数据项按照指定方式更新
    void setSelection(const QRect &rect,QItemSelectionModel::SelectionFlags flags);

    QRegion visualRegionForSelection(const QItemSelection &selection)const ;

private:
    //保存视图的相关内容
    QItemSelectionModel *selections;
    //保存柱状图的区域范围
    QList<QRegion>  MRegionList;
    QList<QRegion>  FRegionList;
    QList<QRegion>  SRegionList;
};

#endif // HISTOGRAMVIEW_H

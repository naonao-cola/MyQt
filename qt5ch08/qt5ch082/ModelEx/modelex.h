#ifndef MODELEX_H
#define MODELEX_H
#include <QAbstractTableModel>
#include <QVector>
#include <QMap>
#include <QStringList>

class ModelEx : public QAbstractTableModel
{
public:
    explicit ModelEx(QObject *parent =nullptr);

    //虚函数声明
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

signals:
public slots:

private:
    QVector<short> army;
    QVector<short> weaponType;
    //保存 数值-文字映射
    QMap<short,QString> armyMap;
    QMap<short,QString> weaponTypeMap;
    QStringList weapon;
    QStringList header;
    //完成表格初始化填充
    void populateModel();
};

#endif // MODELEX_H

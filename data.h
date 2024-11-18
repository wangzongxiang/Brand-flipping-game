#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QMap>
#include <QVector>
class Data : public QObject
{
    Q_OBJECT
public:
    explicit Data();
    QMap<int,QVector<QVector<int>>> num1;
signals:
};

#endif // DATA_H

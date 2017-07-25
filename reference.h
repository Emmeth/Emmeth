#ifndef REFERENCE_H
#define REFERENCE_H

#include <QObject>

class Reference : public QObject
{
    Q_OBJECT
public:
    explicit Reference(QObject *parent = 0);

signals:

public slots:
};

#endif // REFERENCE_H
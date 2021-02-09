#ifndef DOWNLOADPOOL_HPP
#define DOWNLOADPOOL_HPP

#include <QObject>

class DownloadPool : public QObject
{
    Q_OBJECT
public:
    explicit DownloadPool(QObject *parent = nullptr);

signals:

};

#endif // DOWNLOADPOOL_HPP

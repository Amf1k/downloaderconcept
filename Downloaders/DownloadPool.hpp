#ifndef DOWNLOADPOOL_HPP
#define DOWNLOADPOOL_HPP

#include <QObject>

class DownloadPool : public QObject {
  Q_OBJECT
 public:
  explicit DownloadPool(QObject* parent = nullptr);
  void addDownload(const QString& url, const QString& downloadPath);
};

#endif  // DOWNLOADPOOL_HPP

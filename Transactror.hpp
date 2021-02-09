#ifndef TRANSACTROR_HPP
#define TRANSACTROR_HPP
#include <QObject>
#include <QQueue>
#include <QSharedPointer>

namespace Xsolla::Downloader {
class IAction;
class DownloadPool;
class BittorrentSession;

class Transactror : QObject {
  Q_OBJECT
 public:
  explicit Transactror(QObject* parent = nullptr);

 private:
  QQueue<QSharedPointer<IAction>> _actionsQueue;
  QSharedPointer<DownloadPool> _pDownloadPool;
  QSharedPointer<BittorrentSession> _pBittorrentSession;
};
}  // namespace Xsolla::Downloader

#endif  // TRANSACTROR_HPP

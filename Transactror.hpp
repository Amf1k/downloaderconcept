#ifndef TRANSACTROR_HPP
#define TRANSACTROR_HPP
#include <QObject>
#include <QQueue>
#include <QSharedPointer>

#include "Actions/ActionEnv.hpp"

namespace Xsolla::Downloader {
class IAction;
class DownloadPool;
class BittorrentSession;

class Transactror : public QObject {
  Q_OBJECT
 public:
  explicit Transactror(QObject* parent = nullptr);
  void addActions(QQueue<QSharedPointer<IAction>> actionsQueue);
  void start();
  void pause();
  void resume();
  void stop();

 private:
  ActionEnv createActionEnv() const;

 private:
  QQueue<QSharedPointer<IAction>> _actionsQueue;
  QSharedPointer<DownloadPool> _pDownloadPool;
  QSharedPointer<BittorrentSession> _pBittorrentSession;
};
}  // namespace Xsolla::Downloader

#endif  // TRANSACTROR_HPP

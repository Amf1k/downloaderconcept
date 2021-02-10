#ifndef DOWNLOADER_HPP
#define DOWNLOADER_HPP

#include <QObject>
#include <QSharedPointer>
#include <QThread>

#include "ServerAnswer/IServerAnswerService.hpp"

namespace Xsolla::Downloader {

class Transactror;

class Downloader : public QObject {
  Q_OBJECT
 public:
  explicit Downloader(bool p2pEnabled = true, QObject* parent = nullptr);
  void start();
  void checkUpdated();
  void pause();
  void resume();
  void stop();
  void setP2PEnabled(bool value);

 signals:
  void success();
  void progress();
  void error();

 private slots:
  void handleOnSuccessReceivedServerAnswer();
  void handleOnErrorReceivedServerAnswer();

 private:
  bool isP2PEnabled;
  QScopedPointer<QThread> _pWorkerThread;
  QSharedPointer<Transactror> _pTransactor;
  QScopedPointer<IServerAnswerService> _pServerAnswerService;
};

}  // namespace Xsolla::Downloader
#endif  // DOWNLOADER_HPP

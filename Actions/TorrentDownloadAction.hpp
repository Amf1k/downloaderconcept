#ifndef TORRENTDOWNLOADACTION_HPP
#define TORRENTDOWNLOADACTION_HPP

#include <QSharedPointer>

#include "Actions/IAction.hpp"
namespace Xsolla::Downloader {
class Transactror;
class TorrentDownloadAction : public IAction {
  Q_OBJECT
 public:
  explicit TorrentDownloadAction(QSharedPointer<Transactror> pTransactror,
                                 QObject* parent = nullptr);

  // IAction interface
 public:
  void execute() override;
  void stop() override;
  void pause() override;
  void resume() override;
  int progress() override;
  ActionTypeWrapper::ActionType type() override;

 private:
  QSharedPointer<Transactror> _pTransactror;
};
}  // namespace Xsolla::Downloader
#endif  // TORRENTDOWNLOADACTION_HPP

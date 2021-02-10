#include "ActionFactory.hpp"

#include "TorrentDownloadAction.hpp"

Xsolla::Downloader::ActionFactory::ActionFactory(
    QSharedPointer<Xsolla::Downloader::Transactror> pTransactror)
    : IActionFactory(), _pTransactror(pTransactror) {}

QSharedPointer<Xsolla::Downloader::IAction>
Xsolla::Downloader::ActionFactory::createAction(
    ActionTypeWrapper::ActionType actionType) {
  //Понятно что тут надо реализовать фабрику нормально
  return QSharedPointer<TorrentDownloadAction>::create(_pTransactror);
}

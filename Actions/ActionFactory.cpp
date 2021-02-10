#include "ActionFactory.hpp"

#include "TorrentDownloadAction.hpp"

Xsolla::Downloader::ActionFactory::ActionFactory()
    : IActionFactory()) {}

QSharedPointer<Xsolla::Downloader::IAction>
Xsolla::Downloader::ActionFactory::createAction(
    ActionTypeWrapper::ActionType actionType) {
  //Понятно что тут надо реализовать фабрику нормально
  return QSharedPointer<TorrentDownloadAction>::create();
}

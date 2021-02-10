#include "Transactror.hpp"

#include "Actions/IAction.hpp"

Xsolla::Downloader::Transactror::Transactror(QObject* parent)
    : QObject(parent) {}

void Xsolla::Downloader::Transactror::addActions(
    QQueue<QSharedPointer<Xsolla::Downloader::IAction> > actionsQueue) {
  _actionsQueue.append(actionsQueue);
}

void Xsolla::Downloader::Transactror::start() {
  //Псевдо-код
  while (!_actionsQueue.empty()) {
    auto currentAction = _actionsQueue.dequeue();
    currentAction->execute(createActionEnv());
  }
}

void Xsolla::Downloader::Transactror::pause() {}

void Xsolla::Downloader::Transactror::resume() {}

void Xsolla::Downloader::Transactror::stop() {}

Xsolla::Downloader::ActionEnv Xsolla::Downloader::Transactror::createActionEnv()
    const {
  return ActionEnv(_pBittorrentSession, _pDownloadPool);
}

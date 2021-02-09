#include "ServerAnswerService.hpp"

Xsolla::Downloader::ServerAnswerService::ServerAnswerService(QObject* parent)
    : IServerAnswerService(parent) {}

QQueue<QSharedPointer<Xsolla::Downloader::IAction>>
Xsolla::Downloader::ServerAnswerService::getActions() {
  return _pParser->parse(_serverAnswer);
}

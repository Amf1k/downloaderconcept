#include "ServerAnswerService.hpp"

#include "ServerAnswer/XMLServerAnswerParser.hpp"

Xsolla::Downloader::ServerAnswerService::ServerAnswerService(
    QSharedPointer<Transactror> pTransactror,
    QObject* parent)
    : IServerAnswerService(parent),
      _pParser(new XMLServerAnswerParser(pTransactror)) {}

QQueue<QSharedPointer<Xsolla::Downloader::IAction>>
Xsolla::Downloader::ServerAnswerService::getActions() {
  return _pParser->parse(_serverAnswer);
}

#include "XMLServerAnswerParser.hpp"

#include "Actions/ActionFactory.hpp"

Xsolla::Downloader::XMLServerAnswerParser::XMLServerAnswerParser(
    QSharedPointer<Xsolla::Downloader::Transactror> pTransactror)
    : IServerAnswerParser(),
      _pTransactror(pTransactror),
      _pActionFactory(QSharedPointer<ActionFactory>::create(_pTransactror)) {}

QQueue<QSharedPointer<Xsolla::Downloader::IAction>>
Xsolla::Downloader::XMLServerAnswerParser::parse(const QByteArray& data) {
  //Понятно что тут надо применить всю магию парсинга XML

  QQueue<QSharedPointer<Xsolla::Downloader::IAction>> result;
  result.append(_pActionFactory->createAction(
      ActionTypeWrapper::ActionType::BITTORRENT_DOWNLOAD));
  return result;
}

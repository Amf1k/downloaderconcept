#include "XMLServerAnswerParser.hpp"

#include "Actions/ActionFactory.hpp"

Xsolla::Downloader::XMLServerAnswerParser::XMLServerAnswerParser()
    : IServerAnswerParser(),
      _pActionFactory(QSharedPointer<ActionFactory>::create()) {}

QQueue<QSharedPointer<Xsolla::Downloader::IAction>>
Xsolla::Downloader::XMLServerAnswerParser::parse(const QByteArray& data) {
  //Понятно что тут надо применить всю магию парсинга XML

  QQueue<QSharedPointer<Xsolla::Downloader::IAction>> result;
  result.append(_pActionFactory->createAction(
      ActionTypeWrapper::ActionType::BITTORRENT_DOWNLOAD));
  return result;
}

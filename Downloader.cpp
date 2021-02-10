#include "Downloader.hpp"

#include "ServerAnswer/ServerAnswerService.hpp"
#include "ServerAnswer/XMLServerAnswerParser.hpp"
#include "Transactror.hpp"

Xsolla::Downloader::Downloader::Downloader(bool p2pEnabled, QObject* parent)
    : QObject(parent),
      isP2PEnabled(p2pEnabled),
      _pWorkerThread(new QThread),
      _pTransactor(QSharedPointer<Transactror>::create()),
      _pServerAnswerService(new ServerAnswerService()) {
  _pTransactor->moveToThread(_pWorkerThread.data());
  connect(_pServerAnswerService.data(), &IServerAnswerService::successReceive,
          this, &Downloader::handleOnSuccessReceivedServerAnswer);
  connect(_pServerAnswerService.data(), &IServerAnswerService::errorReceive,
          this, &Downloader::handleOnErrorReceivedServerAnswer);

  //тут коннекты от Транзактора естественнос с QueueConnection
}

void Xsolla::Downloader::Downloader::start() {
  _pServerAnswerService->receive();
}

void Xsolla::Downloader::Downloader::checkUpdated() {
  _pServerAnswerService->receive();
}

void Xsolla::Downloader::Downloader::pause() {
  _pTransactor->pause();
}

void Xsolla::Downloader::Downloader::resume() {
  _pTransactor->resume();
}

void Xsolla::Downloader::Downloader::stop() {
  _pTransactor->stop();
}

void Xsolla::Downloader::Downloader::setP2PEnabled(bool value) {
  isP2PEnabled = value;
}

void Xsolla::Downloader::Downloader::handleOnSuccessReceivedServerAnswer() {}

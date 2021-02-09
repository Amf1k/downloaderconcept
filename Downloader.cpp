#include "Downloader.hpp"

#include "IServerAnswerService.hpp"

Xsolla::Downloader::Downloader::Downloader(bool p2pEnabled, QObject* parent)
    : QObject(parent), isP2PEnabled(p2pEnabled) {
  connect(_pServerAnswerService.data(), &IServerAnswerService::successReceive,
          this, &Downloader::handleOnSuccessReceivedServerAnswer);
  connect(_pServerAnswerService.data(), &IServerAnswerService::errorReceive,
          this, &Downloader::handleOnErrorReceivedServerAnswer);

  //тут коннекты от Транзактора естественнос с QueueConnection
}

void Xsolla::Downloader::Downloader::start() {
  _pServerAnswerService->receive();
}

void Xsolla::Downloader::Downloader::checkUpdated() {}

void Xsolla::Downloader::Downloader::pause() {}

void Xsolla::Downloader::Downloader::resume() {}

void Xsolla::Downloader::Downloader::stop() {}

void Xsolla::Downloader::Downloader::setP2PEnabled(bool value) {
  isP2PEnabled = value;
}

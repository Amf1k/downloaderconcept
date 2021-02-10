#include "TorrentDownloadAction.hpp"

Xsolla::Downloader::TorrentDownloadAction::TorrentDownloadAction(
    QSharedPointer<Xsolla::Downloader::Transactror> pTransactror,
    QObject* parent)
    : IAction(parent), _pTransactror(pTransactror) {}

void Xsolla::Downloader::TorrentDownloadAction::execute(ActionEnv env) {}

void Xsolla::Downloader::TorrentDownloadAction::stop() {}

void Xsolla::Downloader::TorrentDownloadAction::pause() {}

void Xsolla::Downloader::TorrentDownloadAction::resume() {}

int Xsolla::Downloader::TorrentDownloadAction::progress() {
  return 0;
}

Xsolla::Downloader::ActionTypeWrapper::ActionType
Xsolla::Downloader::TorrentDownloadAction::type() {
  return ActionTypeWrapper::ActionType::BITTORRENT_DOWNLOAD;
}

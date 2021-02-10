#ifndef ACTIONENV_HPP
#define ACTIONENV_HPP

#include <QSharedPointer>

namespace Xsolla::Downloader {
class BittorrentSession;
class DownloadPool;
struct ActionEnv {
  explicit ActionEnv(QSharedPointer<BittorrentSession> pBittorrentSession,
                     QSharedPointer<DownloadPool> pDownloadPool)
      : pBittorrentSession(pBittorrentSession), pDownloadPool(pDownloadPool) {}
  QSharedPointer<BittorrentSession> pBittorrentSession;
  QSharedPointer<DownloadPool> pDownloadPool;
};

}  // namespace Xsolla::Downloader
#endif  // ACTIONENV_HPP

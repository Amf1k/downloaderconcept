#ifndef BITTORRENTSESSION_HPP
#define BITTORRENTSESSION_HPP
#include <QSharedPointer>

namespace Xsolla::Downloader {
class BittorrentFileInfo;
class BittorrentSession {
 public:
  BittorrentSession();
  QSharedPointer<BittorrentFileInfo> addTorrentFile(
      const QString& torrentPath,
      const QString& downloadPath);
};
}  // namespace Xsolla::Downloader
#endif  // BITTORRENTSESSION_HPP

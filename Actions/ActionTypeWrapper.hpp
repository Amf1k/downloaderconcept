#ifndef ACTIONTYPE_HPP
#define ACTIONTYPE_HPP
#include <QHash>
#include <QString>

namespace Xsolla::Downloader {
struct ActionTypeWrapper {
  enum class ActionType {
    UNKNOWN,
    DOWNLOAD,
    BITTORRENT_DOWNLOAD,
    WAIT,
    EXTRACTED_SIZE,
    EXTRACT,
    PATCH,
    VERSION,
    REQUEST,
    INSTALL
  };

  static ActionType fromString(const QString& actionType) {
    static QHash<QString, ActionType> actionStringToType = {
        {"download", ActionType::DOWNLOAD},
        {"torrent_download", ActionType::BITTORRENT_DOWNLOAD},
        {"wait_actions", ActionType::WAIT},
        {"extracted_size", ActionType::EXTRACTED_SIZE},
        {"extract", ActionType::EXTRACT},
        {"patch", ActionType::PATCH},
        {"version", ActionType::VERSION},
        {"request", ActionType::REQUEST},
        {"install", ActionType::INSTALL}};
    return actionStringToType.value(actionType.toLower(), ActionType::UNKNOWN);
  }
};
}  // namespace Xsolla::Downloader

#endif  // ACTIONTYPE_HPP

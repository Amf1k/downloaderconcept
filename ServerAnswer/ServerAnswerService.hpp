#ifndef SERVERANSWERSERVICE_HPP
#define SERVERANSWERSERVICE_HPP

#include <QObject>
#include <QScopedPointer>

#include "ServerAnswer/IServerAnswerParser.hpp"
#include "ServerAnswer/IServerAnswerService.hpp"

namespace Xsolla::Downloader {
class Transactror;
class ServerAnswerService : public IServerAnswerService {
  Q_OBJECT
 public:
  explicit ServerAnswerService(QSharedPointer<Transactror> pTransactror,
                               QObject* parent = nullptr);

 public:
  void receive() override;
  QQueue<QSharedPointer<IAction>> getActions() override;

 private:
  QScopedPointer<IServerAnswerParser> _pParser;
  QByteArray _serverAnswer;
};
}  // namespace Xsolla::Downloader

#endif  // SERVERANSWERSERVICE_HPP

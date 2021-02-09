#ifndef ISERVERANSWERSERVICE_HPP
#define ISERVERANSWERSERVICE_HPP

#include <QObject>
#include <QQueue>
#include <QSharedPointer>

namespace Xsolla::Downloader {
class IAction;
class IServerAnswerService : public QObject {
  Q_OBJECT
 public:
  virtual ~IServerAnswerService() = default;
  //Тут в зависимости от реализации этого сервиса, можно кешировать,
  //переиспользовать, тестовый подсовывать и тд.
  virtual void receive() = 0;
  virtual QQueue<QSharedPointer<IAction>> getActions() = 0;

 signals:
  void successReceive();
  void errorReceive();

 protected:
  explicit IServerAnswerService(QObject* parent = nullptr) : QObject(parent) {}
};
}  // namespace Xsolla::Downloader

#endif  // ISERVERANSWERSERVICE_HPP

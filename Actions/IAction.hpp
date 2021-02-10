#ifndef IACTION_HPP
#define IACTION_HPP
#include <QObject>

#include "ActionTypeWrapper.hpp"

namespace Xsolla::Downloader {

class IAction : public QObject {
  Q_OBJECT
 public:
  virtual ~IAction() = default;
  virtual void execute() = 0;
  virtual void stop() = 0;
  virtual void pause() = 0;
  virtual void resume() = 0;
  virtual int progress() = 0;
  virtual ActionTypeWrapper::ActionType type() = 0;

 signals:
  void success();
  void error();
  void progressChanged();

 protected:
  explicit IAction(QObject* parent = nullptr) : QObject(parent) {}
};

}  // namespace Xsolla::Downloader

#endif  // IACTION_HPP

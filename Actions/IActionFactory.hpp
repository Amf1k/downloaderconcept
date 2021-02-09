#ifndef IACTIONFACTORY_HPP
#define IACTIONFACTORY_HPP

#include <ActionTypeWrapper.hpp>
#include <QSharedPointer>

namespace Xsolla::Downloader {
class IAction;
class IActionFactory {
 public:
  virtual QSharedPointer<IAction> createAction(
      ActionTypeWrapper::ActionType actionType) = 0;

 protected:
  IActionFactory() = default;
};
}  // namespace Xsolla::Downloader

#endif  // IACTIONFACTORY_HPP

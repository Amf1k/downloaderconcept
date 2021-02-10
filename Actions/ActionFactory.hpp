#ifndef ACTIONFACTORY_HPP
#define ACTIONFACTORY_HPP

#include "Actions/IActionFactory.hpp"
namespace Xsolla::Downloader {
class Transactror;
class ActionFactory : public IActionFactory {
 public:
  ActionFactory();

  // IActionFactory interface
 public:
  QSharedPointer<IAction> createAction(
      ActionTypeWrapper::ActionType actionType) override;
};
}  // namespace Xsolla::Downloader

#endif  // ACTIONFACTORY_HPP

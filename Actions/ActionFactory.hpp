#ifndef ACTIONFACTORY_HPP
#define ACTIONFACTORY_HPP

#include "Actions/IActionFactory.hpp"
namespace Xsolla::Downloader {
class Transactror;
class ActionFactory : public IActionFactory {
 public:
  explicit ActionFactory(QSharedPointer<Transactror> pTransactror);

  // IActionFactory interface
 public:
  QSharedPointer<IAction> createAction(
      ActionTypeWrapper::ActionType actionType) override;

 private:
  QSharedPointer<Transactror> _pTransactror;
};
}  // namespace Xsolla::Downloader

#endif  // ACTIONFACTORY_HPP

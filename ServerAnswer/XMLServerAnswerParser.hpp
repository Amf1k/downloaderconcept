#ifndef XMLSERVERANSWERPARSER_HPP
#define XMLSERVERANSWERPARSER_HPP
#include "ServerAnswer/IServerAnswerParser.hpp"

namespace Xsolla::Downloader {
class Transactror;
class IActionFactory;
class XMLServerAnswerParser : public IServerAnswerParser {
 public:
  explicit XMLServerAnswerParser();

  // IServerAnswerParser interface
 public:
  QQueue<QSharedPointer<IAction>> parse(const QByteArray& data) override;

 private:
  QSharedPointer<IActionFactory> _pActionFactory;
};
}  // namespace Xsolla::Downloader
#endif  // XMLSERVERANSWERPARSER_HPP

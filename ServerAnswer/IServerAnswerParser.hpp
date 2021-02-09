#ifndef ISERVERANSWERPARSER_HPP
#define ISERVERANSWERPARSER_HPP

#include <QByteArray>
#include <QQueue>
#include <QSharedPointer>

namespace Xsolla::Downloader {
class IAction;
class IServerAnswerParser {
 public:
  virtual ~IServerAnswerParser() = default;
  //В данном случае просто проходимся по XML дереву и юзаем IActionFactory.
  //Обработка ошибок естественно внутри парсера,
  // Можно подумать о том, как вынести их наружу, если это надо.
  virtual QQueue<QSharedPointer<IAction>> parse(const QByteArray& data) = 0;

 protected:
  IServerAnswerParser() = default;
};
}  // namespace Xsolla::Downloader

#endif  // ISERVERANSWERPARSER_HPP

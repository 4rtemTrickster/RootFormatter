#include "Text.h"

#include "boost/algorithm/string.hpp"

namespace TextTools
{

Text::Text(const std::string& string)
{
    // TODO(4rtemTrickster): Вопрос в том насколько это эффективно
    boost::split(m_text, string, [](char c) { return '\n' == c; });
}

} // namespace TextTools

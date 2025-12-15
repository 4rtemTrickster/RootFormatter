#pragma once

#include <list>
#include <string>

namespace TextTools
{

class Text final
{

public:

    Text() = default;
    explicit Text(const std::string& string);
    
    Text(const Text&) = default;
    Text(Text&&)  noexcept = default;

    Text &operator = (const Text&) = default;
    Text &operator = (Text&&) = default;

    ~Text() = default;

private:
    std::list<std::string> m_text;
};

}  // namespace TextTools

#include <gtest/gtest.h>

#include "Formatter/Formatter.h"

TEST(SimpleTest, base)
{
    Formatter frm;

    std::string before = R"(#include <iostream>
// blabla
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
)";
    std::string after = frm.format(before);

    ASSERT_EQ(before, after);
}


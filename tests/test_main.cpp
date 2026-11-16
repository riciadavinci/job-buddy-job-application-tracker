#include <gtest/gtest.h>

namespace jobbuddy::testing {


TEST(GoogleTestFrameworkTest, ItWorks) {
    bool flag1 = true;
    EXPECT_TRUE(flag1);
    EXPECT_FALSE(!flag1);
}

}
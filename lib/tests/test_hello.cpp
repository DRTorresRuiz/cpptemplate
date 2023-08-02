/* Copyright 2023 @DRTorresRuiz */
#include <gtest/gtest.h>
#include <hello.h>

TEST(hello, BasicAssertions) {
  EXPECT_EQ("Hello World!", hello::greet("World"));
}

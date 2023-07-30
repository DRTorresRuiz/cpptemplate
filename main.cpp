/* Copyright 2023 @DRTorresRuiz */
#include <fmt/chrono.h>
#include <fmt/color.h>
#include <hello.h>

int main(int argc, char const *argv[]) {
  std::time_t t = std::time(nullptr);
  fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,
             "[{:%Y-%m-%d %H:%M:%S}]: ", fmt::localtime(t));
  fmt::print("{}\n", greet("Mars"));
  return 0;
}

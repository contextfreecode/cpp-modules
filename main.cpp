#include <iostream>
#include <string_view>
#include <vector>

// #include "split.cpp"
import split;

auto main() -> int {
  // DEFAULT_CONTAINER(std::string_view) words = split::split("hello world");
  auto words = split::split("hello world");
  // split::reserve_space(words, "will this work at all?");
  split::split_into(words, "bye y'all");
  for (auto& word: words) {
    std::cout << word << std::endl;
  }
}

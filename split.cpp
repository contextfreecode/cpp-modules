module;

#include <algorithm>
#include <string_view>
#include <vector>

export module split;

namespace split {

// Note: Don't make macros like this!
#define DEFAULT_CONTAINER(Value) std::vector<Value>

// Private to split module! Don't use in outside code!
template<typename Container>
auto reserve_space(Container& container, std::string_view text) -> void {
  auto count = std::count(text.begin(), text.end(), ' ') + 1;
  container.reserve(container.size() + count);
}

export template<typename Container>
auto split_into(Container& container, std::string_view text) -> void {
  // Reserve to avoid multiple allocations.
  reserve_space(container, text);
  // Just walk manually for now.
  std::size_t start = 0;
  while (start <= text.size()) {
    auto stop = text.find(' ', start);
    if (stop == std::string_view::npos) {
      stop = text.size();
    }
    container.push_back(text.substr(start, stop - start));
    start = stop + 1;
  }
}

export auto split(std::string_view text) -> DEFAULT_CONTAINER(std::string_view) {
  std::vector<std::string_view> result;
  split_into(result, text);
  return result;
}

}  // namespace split

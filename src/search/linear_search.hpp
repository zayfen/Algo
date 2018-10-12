#ifndef LINEAR_SEARCH_HPP__
#define LINEAR_SEARCH_HPP__

#include <vector>

template <typename T> 
extern int linear_search(const std::vector<T>& vec, const T& x)
{
  int index = -1;
  for(const auto& element : vec) {
    index++;
    if(element == x) {
      return index;
    }
  }

  return -1;
}

#endif // 
#ifndef BINARY_SEARCH_H__
#define BINARY_SEARCH_H__

template<typename T>
extern int binary_search(const std::vector<T>& vec, const int low, const int high, const T& x) {
  std::cout << "binary_search low " << low << "  high " << high << std::endl;
  if (low > high) { // 没有找到
    return -1;
  }
  
  int middle = low + (high - low) / 2;
  if (x == vec.at(middle)) {
    return middle;
  }
  
  int low_ = vec.at(middle) > x ? low : middle + 1;
  int high_ = vec.at(middle) > x ? middle - 1 : high;
  return binary_search(vec, low_, high_, x);
}
 
#endif // 
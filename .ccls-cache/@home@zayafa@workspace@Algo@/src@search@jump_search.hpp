#ifndef JUMP_SEARCH__
#define JUMP_SEARCH__

#include <cmath>
#include <algorithm>
#include <vector>

template<typename T>
extern int jump_search(const std::vector<T>& vec, const T& x) {
	if (vec.size() == 0) { 
		return -1;
	}
	
  int stepWidth = std::sqrt(vec.size());
  int prevStepIndex = 0;
  int stepIndex = std::min(stepWidth, int(vec.size())) - 1;
	
  while (vec.at(stepIndex) < x) {
    prevStepIndex = stepIndex;
    stepIndex = std::min(stepWidth + stepIndex, int(vec.size() - 1));
    
    if (prevStepIndex == stepIndex) { // 到达尾部，没有找到x元素
      return -1;
    }
  }
  
  // ignore all elements less than x
  while (vec.at(prevStepIndex) < x) {
    prevStepIndex++;
    if (prevStepIndex >= vec.size()) {
      return -1;
    }
  }
  
  // if element is found
  if (vec.at(prevStepIndex) == x) {
    return prevStepIndex;
  }
  
  return -1;
}

#endif // 

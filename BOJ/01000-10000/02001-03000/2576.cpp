// 홀수
#include <iostream>
#include <algorithm>
#include <climits>

int main(void) {
  int input;
  int count = 0;
  int minNum = INT_MAX;
  int sum = 0;

  while (std::cin >> input) {
    if (input & 1) {
      minNum = std::min(input, minNum);
      sum += input;
      count++;
    }
  }
   
  if (count) {
    std::cout << sum << '\n' << minNum;
  }
  else {
    std::cout << -1;
  }

  return 0;
}
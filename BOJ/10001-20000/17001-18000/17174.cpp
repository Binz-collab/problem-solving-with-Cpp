// 전체 계산 횟수

#include <iostream>

int main(void) {
  int n, m;

  std::cin >> n >> m;

  int result = n;

  while (n >= m) {
    n /= m;
    result += n;
  }

  std::cout << result;

  return 0;
}
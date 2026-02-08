// 더하기

#include <iostream>

int main(void) {
  int n, m;
  int input;
  int sum = 0;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> m;
    for (int j = 0; j < m; j++) {
      std::cin >> input;
      sum += input;
    }
    std::cout << sum << '\n';
    sum = 0;
  }

  return 0;
}
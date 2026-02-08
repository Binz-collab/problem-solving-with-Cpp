// 별 찍기 - 6

#include <iostream>

int main(void) {
  int n;

  std::cin >> n;

  for (int i = 0; i < n; i++) {

    for (int j = n; j > n-i; j--) {
      std::cout << ' ';
    }

    for (int j = 0; j < 2*(n-i) - 1; j++) {
      std::cout << '*';
    }
    std::cout << '\n';
  }

  return 0;
}
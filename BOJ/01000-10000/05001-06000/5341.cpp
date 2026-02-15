#include <iostream>

int main(void) {
  int n;
  int num = 0;

  while (std::cin >> n) {
    if (n == 0) {
      break;
    }
    
    for (int i = 1; i <= n; i++) {
      num += i;
    }

    std::cout << num << '\n';
    num = 0;
  }

  return 0;
}
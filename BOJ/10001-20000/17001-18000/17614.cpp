// 369

#include <iostream>

int main(void) {
  int n, temp, a;
  int count = 0;

  std::cin >> n;

  for (int i = 0; i <= n; i++) {
    temp = i;
    while (temp > 0) {
      a = temp % 10;
      if (a == 3 || a == 6 || a == 9) {
        count++;
      }
      temp /= 10;
    }
  }

  std::cout << count;

  return 0;
}
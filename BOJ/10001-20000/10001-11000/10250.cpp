#include <iostream>

int main(void) {
  int n, h, w, input;
  int result;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> h >> w >> input;

    // 1호부터 시작하니까
    result = ((input - 1) % h + 1) * 100 + ((input - 1) / h) + 1;
    std::cout << result << '\n';
  }

  return 0;
}
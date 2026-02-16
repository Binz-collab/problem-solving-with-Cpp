// 이 대회는 이제 제 겁니다

#include <iostream>
#include <algorithm>

int main(void) {
  int A, P, C;
  int result;

  std::cin >> A >> P >> C;

  result = std::max(A+C, P);

  std::cout << result;

  return 0;
}
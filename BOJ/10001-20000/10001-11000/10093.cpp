// 숫자
#include <iostream>
#include <utility> // std::swap을 사용하기 위한 헤더 (보통 iostream에 포함되어 있긴 합니다)

int main(void) {
  // C++ 입출력 속도를 비약적으로 높여주는 마법의 주문
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  // 입력값이 21억 (약 2*10^9)을 초과하므로
  long long a, b;
  std::cin >> a >> b;
  // a, b가 같지 않다는 조건이 없으므로
  if (a == b) {
    std::cout << 0;
  }
  else {
    // 입력값이 크기 순으로 들어온다는 조건이 없으므로
    if (a > b) {
      std::swap(a, b);
    }
    // x < n < y 에서, n의 개수 == y-x-1
    std::cout << b - a - 1 << '\n';
    for (long long i = a+1; i < b; i++) {
      std::cout << i << ' ';
    }
  }
  
  return 0;
}
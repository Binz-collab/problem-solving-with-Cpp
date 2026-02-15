// 어떤 호박의 할로윈 여행

#include <iostream>

int main(void) {
  int A, a, B, b, P;
  bool canMakeRings = false;

  std::cin >> A >> a >> B >> b >> P;

  // case 1: 원판 자체의 반지름이 충분히 크고,
  // && A 고리 또는 B 고리를 다른 고리 안에 그릴 수 있는 경우
  if (P >= A && P >= B) {
    if (A <= b || B <= a) {
      canMakeRings = true;
    }
  }

  // case 2: 나란히 놓을 정도로 원판의 지름이 충분할 때
  if (P >= A + B) {
    canMakeRings = true;
  }
  

  if (canMakeRings) {
    std::cout << "Yes";
  }
  else {
    std::cout << "No";
  }  

  return 0;
}
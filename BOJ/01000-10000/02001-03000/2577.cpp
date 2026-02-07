// 숫자의 개수

#include <iostream>
#include <iterator>

int main(void) {
  int a, b, c, num, n;
  int count[10] = { 0 };

  std::cin >> a >> b >> c;
  n = a * b * c;

  while (n > 0) {
    num = n % 10;
    count[num]++;
    n = n / 10;
  }

  for (int i = 0; i < std::size(count); i++)
    std::cout << count[i] << '\n';
  
  return 0;
}
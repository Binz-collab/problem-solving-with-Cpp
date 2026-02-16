// 영화감독 숌
#include <iostream>
#include <iterator>
#include <string>

int main(void) {
  int n, temp;
  int num = 0;
  int count = 0;
  std::string s;

  std::cin >> n;

  while (count < n) {
    temp = ++num;
    s = std::to_string(temp);
    // std::find(s.begin(), s.end(), "666");
    if (s.find("666") != std::string::npos) {
      count++;
    }
  }

  std::cout << num;

  return 0;
}
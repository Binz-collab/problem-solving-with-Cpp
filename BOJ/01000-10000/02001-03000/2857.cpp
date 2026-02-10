#include <iostream>
#include <string>

int main(void) {
  std::string s, sub;
  bool fbi = false;

  
  for (int i = 0; i < 5; i++) {
    std::cin >> s;
    if (s.find("FBI") != std::string::npos) {
      fbi = true;
      std::cout << i+1 << ' ';
    }
  }
  

  if (!fbi) {
    std::cout << "HE GOT AWAY!" << '\n';
  }

  return 0;
}
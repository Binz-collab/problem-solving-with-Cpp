// 숫자의 합

#include <iostream>
#include <string>

int main(void) {
    int n;
    std::string s;
    int sum = 0;
    
    std::cin >> n;
    std::cin >> s;

    for (int i = 0; i < n; i++) {
      sum += char(s[i]) - '0';
    }

    std::cout << sum;
    
    return 0;
}
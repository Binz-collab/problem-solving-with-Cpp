// 스키테일 암호

#include <iostream>

int main(void) {
    std::string s;
    std::string answer;
    int n;

    std::cin >> n;
    std::cin >> s;
    
    
    for (int i = 0; i < s.length(); i += n) {
        answer = answer + s[i];
    }
    
    std::cout << answer;

    return 0;
}
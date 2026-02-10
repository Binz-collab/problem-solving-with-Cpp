#include <iostream>
#include <algorithm>
#include <string>

int main(void) {
    std::string s, t;
    bool isPalindrome = true;
    
    std::cin >> s;
    // 1. t의 크기를 미리 확보해야 함 (필수!)
    t.resize(s.length());
    // 2. t.begin()을 넘겨줘야 함 - algorithm.h
    std::copy(s.begin(), s.begin() + s.length(), t.begin());
    // 3. reverse 함수는 리턴값이 없음 - algorithm.h
    std::reverse(t.begin(), t.begin() + t.length());
    
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != t[i]) {
            isPalindrome = false;
            break;
        }
    }
    
    std::cout << isPalindrome;
    
    return 0;
}
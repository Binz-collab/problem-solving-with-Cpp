// 수학은 체육과목 입니다

#include <iostream>

int main(void) {
    long long n;
    long long result = 4;
    
    std::cin >> n;
    
    if (n > 1) {
        result = n + 3 + (n - 1) * 3;
    }

    std::cout << result;
    
    return 0;
}
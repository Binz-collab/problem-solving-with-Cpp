// 막대기
#include <iostream>

int main() {
    int X;
    std::cin >> X;

    int cnt = 0;

    while (X > 0) {
        if (X % 2 == 1) cnt++;
        X /= 2;
    }

    std::cout << cnt << '\n';
    
    return 0;
}
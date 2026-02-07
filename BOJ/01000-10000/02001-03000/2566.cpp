// 최댓값

#include <iostream>

int main(void) {
    int a, b;
    int n;
    int max = -1;
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cin >> n;
            if (n > max) {
                max = n;
                a = i+1;
                b = j+1;
            }
        }
    }
    
    std::cout << max << '\n';
    std::cout << a << ' ' << b;
    
    return 0;
}
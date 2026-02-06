#include <iostream>

int main(void) {
    int h, m;
    
    std::cin >> h >> m;
    
    if (m >= 45) {
        m -= 45;
    }
    
    else {
        if (h > 0) {
            h -= 1;
        }
        else {
            h = 23;
        }
        m = m + 60 - 45;
    }
    
    std::cout << h << ' ' << m;
    
    return 0;
}
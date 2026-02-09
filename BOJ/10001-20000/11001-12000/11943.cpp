#include <iostream>
#include <algorithm>

int main(void) {
    int a, b, c, d;
    int result;
    
    std::cin >> a >> b >> c >> d;
    
    result = std::min(a + d, b + c);
    std::cout << result;
    
    return 0;
}
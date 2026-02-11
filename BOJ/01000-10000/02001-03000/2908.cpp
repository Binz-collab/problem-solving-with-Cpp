#include <iostream>
#include <iterator>
#include <algorithm>

int main(void) {
    std::string a, b, answer;
    
    std::cin >> a >> b;
    
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    a > b ? answer = a : answer = b;
    
    std::cout << answer;
        
    return 0;
}
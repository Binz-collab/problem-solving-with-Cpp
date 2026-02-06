#include <iostream>
#include <string>

int main(void) {
    std::string s;
    int count = 0;
    
    while (std::cin >> s) {
        count++;
    }
    
    std::cout << count;
    
    return 0;
}
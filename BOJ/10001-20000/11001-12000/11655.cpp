// ROT13
#include <iostream>
#include <string>

const int MAX = 26;

int main() {
    std::string line;
    std::getline(std::cin, line);
    
    for (char c : line) {
        if (c >= 'A' && c <= 'Z') {
            std::cout << char('A' + ((c  - 'A' + 13) % MAX));
        }

        else if (c >= 'a' && c <= 'z') {
            std::cout << char('a' + ((c - 'a' + 13) % MAX));
        }

        else {
            std::cout << c;
        }
    }

    return 0;
}

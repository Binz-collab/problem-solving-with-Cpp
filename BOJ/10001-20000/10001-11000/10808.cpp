// 알파벳 개수
#include <iostream>

const int SIZE = 26;

int a[SIZE];

int main() {
    char c;
    while (std::cin >> c) {
        a[c - 'a']++;
    }

    for (int n : a) {
        std::cout << n << ' ';
    }

    std::cout << '\n';

    return 0;
}
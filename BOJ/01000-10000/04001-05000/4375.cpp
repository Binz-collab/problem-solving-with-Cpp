// 1
#include <iostream>
#include <string>

int main() {
    int q;
    while (std::cin >> q) {
        int cnt = 1;
        int num = 1;
        while (true) {
            if (num % q == 0) {
                break;
            }
            cnt++;
            num = (num * 10 + 1) % q;
        }
        std::cout << cnt << '\n';
    }

    return 0;
}
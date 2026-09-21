// 트럭 주차
#include <iostream>

const int SIZE = 100;
int t[SIZE];

int main() {
    int price[4] = { 0 };

    std::cin >> price[1] >> price[2] >> price[3];

    for (int i = 0; i < 3; i++) {
        int start, stop;
        std::cin >> start >> stop;
        for (int i = start; i < stop; i++) {
            t[i]++;
        }
    }

    int bill = 0;
    for (const int n : t) {
        bill += n * price[n];
    }

    std::cout << bill << '\n';

    return 0;
}
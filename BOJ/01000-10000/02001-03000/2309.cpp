// 일곱 난쟁이
#include <iostream>
#include <array>
#include <algorithm>

const int NUM = 9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::array<int, NUM> a;
    int sum = 0;

    for (int i = 0; i < NUM; i++) {
        std::cin >> a[i];
        sum += a[i];
    }

    bool isClear = false; 

    for (int i = 0; i < NUM - 1; i++) {
        if (isClear) break;
        for (int j = i+1; j < NUM; j++) {
            if (sum - (a[i] + a[j]) == 100) {
                isClear = true;
                a[i] = 0;
                a[j] = 0;
                break;
            }
        }
    }

    std::sort(a.begin(), a.end());

    for (int i = 2; i < NUM; i++) {
        std::cout << a[i] << '\n';
    }

    return 0;
}
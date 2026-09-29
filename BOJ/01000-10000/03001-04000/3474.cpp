// 교수가 된 현우
#include <iostream>

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        std::cin >> N;

        int cnt2 = 0;
        int cnt5 = 0;

        for (int i = 2; i <= N; i *= 2) {
            cnt2 += N / i;
        }

        for (int i = 5; i <= N; i *= 5) {
            cnt5 += N / i;
        }

        std::cout << std::min(cnt2, cnt5) << '\n';
    }

    return 0;
}
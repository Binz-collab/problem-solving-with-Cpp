// 동전 뒤집기
#include <iostream>
#include <string>

const int SIZE = 22;
const int INF = 987654321;

int a[SIZE];
int N;

int min = INF;

void go(int here) {
    // base case
    if (here == N) {
        int cnt = 0;
        for (int i = 1; i < (1 << N); i <<= 1) {
            int column = 0;
            for (int j = 0; j < N; j++) {
                if (i & a[j]) {
                    column++;
                }
            }
            cnt += std::min(column, N - column);
        }
        min = std::min(cnt, min);
        return;
    }

    go(here + 1);

    a[here] = ~a[here];

    go(here + 1);
}

int main() {
    std::cin >> N;
    std::string s;
    for (int i = 0; i < N; i++) {
        std::cin >> s;
        int mask = 1;
        for (const char& c : s) {
            if (c == 'T') {
                a[i] |= mask;
            }
            mask <<= 1;
        }
    }

    go(0);

    std::cout << min << '\n';

    return 0;
}
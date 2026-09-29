// 기상캐스터
#include <iostream>
#include <string>

const int SIZE = 101;
int map[SIZE][SIZE];

int main() {
    int N, M;
    std::cin >> N >> M;

    std::string s;
    for (int i = 0; i < N; i++) {
        std::cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == '.') {
                map[i][j] = -1;
            } else {
                map[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                int cnt = 1;
                while (map[i][j + 1] == -1) {
                    map[i][j + 1] = cnt++;
                    j++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << map[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
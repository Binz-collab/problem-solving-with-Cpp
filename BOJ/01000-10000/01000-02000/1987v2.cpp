// 알파벳
#include <iostream>
#include <string>

const int SIZE = 22;
char map[SIZE][SIZE];
int R, C;
int result = 0;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x, int cnt, int alphabet) {
    int value = 1 << map[y][x] - 'A';

    if (alphabet & value) {
        result = std::max(result, cnt);
        return;
    }

    alphabet |= value;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;

        dfs(ny, nx, cnt + 1, alphabet);
    }
}

int main() {
    std::cin >> R >> C;
    std::string s;
    for (int i = 0; i < R; i++) {
        std::cin >> s;
        for (int j = 0; j < C; j++) {
            map[i][j] = s[j];
        }
    }

    if (R == 1 && C == 1) {
        result = 1;
    } else {
        dfs(0, 0, 0, 0);
    }

    std::cout << result << '\n';

    return 0;
}

// 최대 400칸
// 1 ≤ 최댓값 ≤ 26
// 격자 기반 dfs
// 알파벳
#include <iostream>

const int SIZE = 22;
char a[SIZE][SIZE];
int R, C;
int result = 0;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void go(int y, int x, int num, int cnt) {
    result = std::max(result, cnt);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        int next = (1 << (int)(a[ny][nx] - 'A'));

        if (!(num & next)) {
            go(ny, nx, num | next, cnt + 1);
        }
    }
}

int main() {
    std::cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            std::cin >> a[i][j];
        }
    }

    go(0, 0, 1 << (int)(a[0][0] - 'A'), 1);

    std::cout << result << '\n';

    return 0;
}
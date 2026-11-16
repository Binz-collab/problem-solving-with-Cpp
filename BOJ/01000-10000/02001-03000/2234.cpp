// 성곽
#include <iostream>

const int SIZE = 51;

int map[SIZE][SIZE], visited[SIZE][SIZE];
int compSize[SIZE * SIZE];

int cnt, max, big;

const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { -1, 0, 1, 0 };

int dfs(int y, int x, int cnt) {
    if (visited[y][x]) return 0;

    visited[y][x] = cnt;

    int result = 1;

    for (int i = 0; i < 4; i++) {
        if (!(map[y][x] & 1 << i)) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            result += dfs(ny, nx, cnt);
        }
    }

    return result;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                cnt++;
                // visited[i][j] = cnt;
                compSize[cnt] = dfs(i, j, cnt);
                max = std::max(max, compSize[cnt]);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i + 1 < M) {
                // int a = map[i+1][j];
                // int b = map[i][j];
                int a = visited[i+1][j];
                int b = visited[i][j];

                if (a != b) {
                    big = std::max(big, compSize[a] + compSize[b]);
                }
            }

            if (j + 1 < N) {
                // int a = map[i][j+1];
                // int b = map[i][j];
                int a = visited[i][j+1];
                int b= visited[i][j];
                
                if (a != b) {
                    big = std::max(big, compSize[a] + compSize[b]);
                }
            }
        }
    }

    std::cout << cnt << '\n' << max << '\n' << big << '\n';

    return 0;
}
// 성곽
#include <iostream>

const int SIZE = 51;
int map[SIZE][SIZE], visited[SIZE][SIZE];
int compSize[SIZE * SIZE];
int cnt, max, big;

// 비트 방향 맞춰서
const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { -1, 0, 1, 0 };

int dfs(int y, int x, int cnt) {
    // 되돌아가는 경우 방지
    if (visited[y][x]) return 0;

    // 몇 번 구역인지 표시
    visited[y][x] = cnt;

    // 넓이 카운트
    int result = 1;

    // 4방향 탐색
    for (int i = 0; i < 4; i++) {
        // 진행하고자 하는 방향에 벽이 있는지 체크
        if (!(map[y][x] & (1 << i))) {
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
                compSize[cnt] = dfs(i, j, cnt);
                max = std::max(max, compSize[cnt]);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            // 가로 방향으로 인접한 두 칸이 같은 방인지 체크
            if (i + 1 < M) {
                int a = visited[i + 1][j];
                int b = visited[i][j];
                // 다르면 합쳐보기
                if (a != b) {
                    big = std::max(big, compSize[a] + compSize[b]);
                }
            }
            // 세로 방향으로 인접한 두 칸이 같은 방인지 체크
            if (j + 1 < N) {
                int a = visited[i][j + 1];
                int b = visited[i][j];
                if (a != b) {
                    big = std::max(big, compSize[a] + compSize[b]);
                }
            }
        }
    }

    std::cout << cnt << '\n' << max << '\n' << big << '\n';

    return 0;
}
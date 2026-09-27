// 안전 영역
#include <iostream>

const int SIZE = 101;
int map[SIZE][SIZE];
bool visited[SIZE][SIZE];

int min = 101;
int max = 1;
// 만약 모든 칸의 높이가 같다면 1이 최댓값임.
int result = 1;
int cnt = 0;
int n;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int level, int y, int x) {
    if (visited[y][x]) return;

    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (map[ny][nx] <= level) continue;
        if (!visited[ny][nx]) {
            dfs(level, ny, nx);
        }
    }
}

int main() {
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> map[i][j];
            min = std::min(map[i][j], min);
            max = std::max(map[i][j], max);
        }
    }

    // 입력 범위가 최대 100이라 3중 반복문으로 전체를 돌려도 1초 내에 실행 가능함.  
    for (int i = min; i < max; i++) {
        std::fill(&visited[0][0], &visited[0][0] + SIZE * SIZE, false);
        cnt = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (map[j][k] > i && !visited[j][k]) {
                    dfs(i, j, k);
                    cnt++;
                }
            }
        }

        result = std::max(cnt, result);
    }

    std::cout << result << '\n';

    return 0;
}
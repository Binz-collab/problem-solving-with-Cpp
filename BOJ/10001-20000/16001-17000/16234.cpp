// 인구 이동
#include <iostream>
#include <vector>
#include <utility>

const int SIZE = 51;
int map[SIZE][SIZE];
int visited[SIZE][SIZE];

int N, L, R;
int sum = 0;
int cnt = 0;

std::vector<std::pair<int, int>> v;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x, std::vector<std::pair<int, int>> &v) {

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if (visited[ny][nx]) continue;
        int d = std::abs(map[ny][nx] - map[y][x]); 
        if (d < L || d > R) continue;

        visited[ny][nx] = 1;
        v.push_back(std::make_pair(ny, nx));
        sum += map[ny][nx];
        dfs(ny, nx, v);
    }
}
 
int main() {
    std::cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
        }
    }

    while (true) {
        bool isOver = true;
        std::fill(&visited[0][0], &visited[0][0] + SIZE * SIZE, 0);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back(std::make_pair(i, j));
                    sum = map[i][j];

                    dfs(i, j, v);

                    if (v.size() == 1) continue;

                    for (const auto p : v) {
                        map[p.first][p.second] = sum / v.size();
                        isOver = false;
                    }
                }
            }
        }
        if (isOver) break;
        cnt++;
    }

    std::cout << cnt << '\n';

    return 0;
}
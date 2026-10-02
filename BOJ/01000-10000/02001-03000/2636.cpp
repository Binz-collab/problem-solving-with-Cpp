// 치즈
#include <iostream>
#include <vector>
#include <utility> 

const int SIZE = 101;
int map[SIZE][SIZE];
int visited[SIZE][SIZE];

int N, M, cnt, cnt2;
std::vector<std::pair<int, int>> v;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1 ,0, -1 };

void go(int y, int x) {
    visited[y][x] = 1;

    if (map[y][x] == 1) {
        v.push_back(std::make_pair(y, x));
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        // if (map[ny][nx] == 0) continue;
        if (!visited[ny][nx]) {
            go(ny, nx);
        }
    }

    return;
}

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
        }
    }

    while (true) {
        std::fill(&visited[0][0], &visited[0][0] + SIZE * SIZE, 0);
        v.clear();
        go(0, 0);

        cnt2 = v.size();
        for (const auto &p : v) {
            map[p.first][p.second] = 0;
        }

        bool isEnd = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] != 0) {
                    isEnd = false;
                }
            }
        }

        cnt++;
        if (isEnd) break;
    }

    std::cout << cnt << '\n' << cnt2 << '\n';

    return 0;
}
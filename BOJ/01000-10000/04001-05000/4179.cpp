// 불!
#include <iostream>

const int SIZE = 1001;
char map[SIZE][SIZE];
int visited[SIZE][SIZE];
int fireVisited[SIZE][SIZE];

const int INF = 999999999;

int R, C, y, x;
int sy, sx;
int result = -1;

std::queue<std::pair<int, int>> q;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {
    std::cin >> R >> C;

    std::fill(&fireVisited[0][0], &fireVisited[0][0] + SIZE * SIZE, INF);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            std::cin >> map[i][j];
            if (map[i][j] == 'J') {
                sy = i;
                sx = j;
            } else if (map[i][j] == 'F') {
                fireVisited[i][j] = 1;
                q.push(std::make_pair(i, j));
            }
        }
    }

    while (q.size()) {
        std::tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if (map[ny][nx] == '#') continue;
            if (fireVisited[ny][nx] != INF) {
                q.push(std::make_pair(ny, nx));
                fireVisited[ny][nx] = fireVisited[y][x] + 1;
            }
        }
    }

    visited[sy][sx] = 1;
    q.push(std::make_pair(sy, sx));

    while (q.size()) {
        std::tie(y, x) = q.front();
        q.pop();

        // 탈출 성공
        if (y == 0 || y == R - 1 || x == 0 || x == C - 1) {
            result = visited[y][x];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if (map[ny][nx] == '#') continue;
            if (fireVisited[ny][nx] <= visited[ny][nx] + 1) continue;
            if (!visited[ny][nx]) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push(std::make_pair(ny, nx));
            }
        }
    }

    if (result > 0) {
        std::cout << result << '\n';
    } else {
        std::cout << "IMPOSSIBLE" << '\n';
    }

    return 0;
}
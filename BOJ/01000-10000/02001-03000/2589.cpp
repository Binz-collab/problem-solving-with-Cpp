// 보물섬
#include <iostream>
#include <utility>
#include <queue>

const int SIZE = 50;
char map[SIZE][SIZE];
int visited[SIZE][SIZE];

int N, M;
int result = 0;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void bfs(int y, int x) {
    // 매 시작마다 visited 배열을 0으로 초기화
    memset(visited, 0, sizeof(visited));
    // std::fill(visited[0][0], visited[0][0] + SIZE * SIZE, 0);

    visited[y][x] = 1;

    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(y, x));

    while(!q.empty()) {
        std::tie(y, x) = q.front(); q.pop();
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (map[ny][nx] == 'W') continue;
            if (!visited[ny][nx]) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push(std::make_pair(ny, nx));
                // 최댓값을 구한다.
                result = std::max(result, visited[ny][nx]);
            }
        }
    }
}

int main() {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
        }
    }

    // 모든 지점을 기준으로 최단 거리를 구한다.
    // map을 순회하면서 임의의 v 지점부터 u 지점까지 거리를 전부 찾는다.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'L') {
                bfs(i, j);
            }
        }
    }

    std::cout << result - 1 << '\n';

    return 0;
}
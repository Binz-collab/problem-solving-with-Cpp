// 유기농 배추
#include <iostream>

const int SIZE = 51;
int map[SIZE][SIZE];
bool visited[SIZE][SIZE];

int N, M, cnt;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x) {
    // if (visited[y][x]) return;
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (map[ny][nx] == 0) continue;
        if (!visited[ny][nx]) {
            dfs(ny, nx);
        }
    }
    return;
}

int main() {
    int T, K;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        std::cin >> M >> N >> K;
        
        // 매 케이스마다 판도 갈아줘야 함.
        cnt = 0;
        std::fill(&map[0][0], &map[0][0] + SIZE * SIZE, 0);
        std::fill(&visited[0][0], &visited[0][0] + SIZE * SIZE, false);

        for (int i = 0; i < K; i++) {
            int x, y;
            std::cin >> x >> y;
            map[y][x] = 1;
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                // 지도 상에서 갈 수 있고, 아직 방문하지 않았다면 진입.
                if (map[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        std::cout << cnt << '\n';
    }

    return 0;
}
// 영역 구하기
#include <iostream>
#include <vector>
#include <algorithm>

const int SIZE = 101;
int map[SIZE][SIZE];
bool visited[SIZE][SIZE];

int M, N;
int cnt = 0;
std::vector<int> v;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int dfs(int y, int x) {

    visited[y][x] = true;
    int visitCount = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
        if (map[ny][nx] != 0) continue;
        if (!visited[ny][nx]) {
            visitCount += dfs(ny, nx);
        }
    }

    return visitCount;
};

int main() {
    std::cin >> M >> N;

    // 직사각형 영역만큼 색칠하기
    int K;
    std::cin >> K;
    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                map[M - i - 1][j] = 1;
            }
        }
    }

    // dfs
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[j][i] == 0 && !visited[j][i]) {
                v.push_back(dfs(j, i));
                cnt++;
            }
        }
    }

    // 출력
    std::cout << cnt << '\n';
    std::sort(v.begin(), v.end());
    for (const int n : v) {
        std::cout << n << ' ';
    }

    return 0;
}
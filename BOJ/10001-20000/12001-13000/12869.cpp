// 뮤탈리스크
#include <iostream>
#include <queue>

struct SCV {
    int x, y, z;
};

std::queue<SCV> q;

int v[3];

const int INF = 66;
int result = INF;
int visited[INF][INF][INF];
int d[][3] = {
    { 9, 3, 1 },
    { 9, 1, 3 },
    { 3, 9, 1 },
    { 3, 1, 9 },
    { 1, 3, 9 },
    { 1, 9, 3 },
};

int solve(int x, int y, int z) {
    visited[x][y][z] = 1;
    q.push({ x, y, z });

    while(q.size()) {
        int x, y, z;
        x = q.front().x;
        y = q.front().y;
        z = q.front().z;
        q.pop();

        if (visited[0][0][0]) break;

        for (int i = 0; i < 6; i++) {
            int nx = std::max(0, x - d[i][0]);
            int ny = std::max(0, y - d[i][1]);
            int nz = std::max(0, z - d[i][2]);

            if (visited[nx][ny][nz]) continue;
            
            visited[nx][ny][nz] = visited[x][y][z] + 1;
            q.push({ nx, ny, nz });
        }
    }

    return visited[0][0][0] - 1;
}

int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> v[i];
    }

    int result = solve(v[0], v[1], v[2]);

    std::cout << result << '\n';

    return 0;
}
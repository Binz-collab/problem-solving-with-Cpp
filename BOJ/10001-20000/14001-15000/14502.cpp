// 연구소
#include <iostream>
#include <vector>
#include <utility>

const int SIZE = 10;
int map[SIZE][SIZE];
int visited[SIZE][SIZE];

int N, M;
int result = 0;
std::vector<std::pair<int, int>> virusList;
std::vector<std::pair<int, int>> wallList;

const int dy[] = { -1, 0, 1, 0};
const int dx[] = { 0, 1, 0, -1};

void dfs(int y, int x) {

    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (map[ny][nx] == 1) continue;
        if (!visited[ny][nx]) {
            dfs(ny, nx);
        }
    }

    return;
}

int solve() {
    std::fill(&visited[0][0], &visited[0][0] + SIZE * SIZE, 0);
    for (const auto p : virusList) {
        visited[p.first][p.second] = 1;
        dfs(p.first, p.second);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0 && !visited[i][j]) {
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
            if (map[i][j] == 2) virusList.push_back({i, j});
            if (map[i][j] == 0) wallList.push_back({i, j});
        }
    }

    for (int i = 0; i < wallList.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                map[wallList[i].first][wallList[i].second] = 1;
                map[wallList[j].first][wallList[j].second] = 1;
                map[wallList[k].first][wallList[k].second] = 1;

                // int r = solve();
                // if (r > result) {
                //     std::cout << '(' << wallList[i].first << ", " << wallList[i].second << ')' << ", ";
                //     std::cout << '(' << wallList[j].first << ", " << wallList[j].second << ')' << ", ";
                //     std::cout << '(' << wallList[k].first << ", " << wallList[k].second << ')' << '\n';
                //     result = r;
                // }

                result = std::max(result, solve());

                map[wallList[i].first][wallList[i].second] = 0;
                map[wallList[j].first][wallList[j].second] = 0;
                map[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }

    std::cout << result << '\n';

    return 0;
}
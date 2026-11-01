// 게리맨더링
#include <iostream>
#include <vector>

const int SIZE = 11;
const int INF = 987654321;

std::vector<int> adj[SIZE];
int team[SIZE];
int population[SIZE];
int visited[SIZE];

std::pair<int, int> dfs(int here, int value) {
    visited[here] = 1;
    std::pair<int, int> result = { 1, population[here] };

    for (const int there: adj[here]) {
        if (visited[there]) continue;
        if (team[there] != value) continue;
        
        std::pair<int, int> tmp = dfs(there, value);
        
        result.first += tmp.first;
        result.second += tmp.second;
    }

    return result;
}

int main() {
    int N;
    std::cin >> N;
    
    for (int i = 1; i <= N; i++) {
        std::cin >> population[i];
    }

    for (int i = 1; i <= N; i++) {
        int M;
        std::cin >> M;
        for (int j = 0; j < M; j++) {
            int tmp;
            std::cin >> tmp;
            adj[i].push_back(tmp);
            adj[tmp].push_back(i);
        }
    }

    int result = INF;

    for (int i = 1; i < (1 << N) - 1; i++) {
        std::fill(visited, visited + SIZE, 0);
        std::fill(team, team + SIZE, 0);
        int idx1, idx2;
        idx1 = idx2 = -1;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                // team[i] = 1;
                team[j + 1] = 1;
                idx1 = j + 1;
            } else {
                idx2 = j + 1;
            }
        }

        std::pair<int, int> team1, team0;

        team1 = dfs(idx1, 1);
        team0 = dfs(idx2, 0);

        if (team1.first + team0.first == N) {
            result = std::min(result, std::abs(team1.second - team0.second));
        }
    }

    std::cout << (result == INF ? -1 : result) << '\n';

    return 0;
}
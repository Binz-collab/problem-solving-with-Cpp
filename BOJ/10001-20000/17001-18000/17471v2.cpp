// 게리맨더링
#include <iostream>
#include <vector>
#include <utility>

const int SIZE = 11;
const int INF = 987654321;

std::vector<int> adj[SIZE];
int visited[SIZE], population[SIZE], comp[SIZE];
int result = INF;

std::pair<int, int> dfs(int here, int value) {
    visited[here] = 1;
    std::pair<int, int> result = { 1, population[here] };

    for (const int there: adj[here]) {
        // 다른 진영이면 패스
        if (comp[there] != value) continue;
        // 이미 방문했으면 패스
        if (visited[there]) continue;

        std::pair<int, int> tmp = dfs(there, value);

        result.first += tmp.first;
        result.second += tmp.second;
    }

    return result;
}

int main() {
    int N, M;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> population[i];
    }

    // 인접 리스트에 양방향 간선 추가
    // 이때 중복 검사는 하지 않는다 
    for (int i = 1; i <= N; i++) {
        std::cin >> M;
        for (int j = 0; j < M; j++) {
            int tmp;
            std::cin >> tmp;
            adj[i].push_back(tmp);
            adj[tmp].push_back(i);
        }
    }

    // red: 0, blue: 1 로 표현
    // N = 6일 때,
    // 1000000 - 1 == 111111
    // 000001 ≤ i ≤ 111110 (몰빵 빼고, 모든 조합에 대해서 수행)
    for (int i = 1; i < (1 << N) - 1; i++) {
        std::fill(comp, comp + SIZE, 0);
        std::fill(visited, visited + SIZE, 0);

        int idx1, idx2;
        idx1 = idx2 = -1;
        
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                comp[j + 1] = 1;
                idx1 = j + 1;
            } else {
                idx2 = j + 1;
            }
        }

        // DFS를 진영 별로 딱 1 번씩만 수행
        std::pair<int, int> comp1 = dfs(idx1, 1);
        std::pair<int, int> comp2 = dfs(idx2, 0);

        // 모든 노드를 방문한 경우 (같은 진영의 노드가 전부 연결된 경우)
        if (comp1.first + comp2.first == N) {
            result = std::min(result, std::abs(comp1.second - comp2.second));
        }
    }

    std::cout << (result == INF ? -1 : result) << '\n';

    return 0;
}
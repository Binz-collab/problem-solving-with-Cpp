// 트리
#include <iostream>
#include <vector>

const int SIZE = 51;
std::vector<int> adj[SIZE];

int r;

int dfs(int here) {
    int result = 0;
    // int child = 0;

    if (adj[here].empty()) return 1;

    for (int there : adj[here]) {
        // 절단 지점 하위 트리는 방문하지 않음
        if (there == r) continue;

        result += dfs(there);
        // child++;
    }

    // if (child == 0) return 1;

    return result;
}

int main() {
    int N, tmp, root;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> tmp;
        if (tmp == -1) {
            root = i;
        } else {
            adj[tmp].push_back(i);
        }
    }
    
    std::cin >> r;

    if (r == root) {
        std::cout << 0 << '\n';
    } else {
        std::cout << dfs(root) << '\n';
    }

    return 0;
}
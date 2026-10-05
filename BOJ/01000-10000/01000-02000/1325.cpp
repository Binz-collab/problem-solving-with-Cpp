// 효율적인 해킹
#include <iostream>
#include <vector>

const int SIZE = 1000001;

std::vector<int> adj[SIZE];
int visited[SIZE];
int dp[SIZE];

int dfs(int here) {
    int result = 1;

    for (const int there : adj[here]) {
        if (visited[there]) continue;
        visited[there] = 1;
        result += dfs(there);
    }

    return result;
}

int main() {
    int N, M;
    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        adj[b].push_back(a);
    }

    int max;
    for (int i = 1; i <= N; i++) {
        memset(visited, 0, sizeof(visited));
        dp[i] = dfs(i);
        max = std::max(dp[i], max);
    }

    for (int i = 0; i <= N; i++) {
        if (max == dp[i]) {
            std::cout << i << ' ';
        }
    }

    return 0;
}



// int main() {
//     int N, M;
//     std::cin >> N >> M;
//     for (int i = 0; i < M; i++) {
//         int a, b;
//         std::cin >> a >> b;
//         adj[b].push_back(a);
//     }

//     int max = 0;
//     std::vector<int> mList;
//     for (int i = 1; i <= N; i++) {
//         int len = adj[i].size();
//         if (len > max) {
//             mList.clear();
//             mList.push_back(i);
//             max = len;
//         } else if (len == max) {
//             mList.push_back(i);
//         }
//     }

//     std::sort(mList.begin(), mList.end());

//     for (const int n : mList) {
//         std::cout << n << ' ';
//     }

//     return 0;
// }
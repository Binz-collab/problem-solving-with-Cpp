// 숨바꼭질 4
#include <iostream>
#include <queue>
#include <vector>

const int SIZE = 100001;
int visited[SIZE];
int prev[SIZE];

std::vector<int> route;
// N == K 일 때 걸리는 시간 값으로 초기화
int result = 0;

int main() {
    int N, K;
    std::cin >> N >> K;

    std::queue<int> q;
    q.push(N);
    visited[N] = 1;

    while (q.size()) {
        int now = q.front();
        q.pop();

        // 모든 경로를 탐색할 필요가 없음
        if (now == K) {
            result = visited[K];
            break;
        }

        for (const int next : { now + 1, now - 1, now * 2}) {
            if (next < 0 || next >= SIZE) continue;
            if (!visited[next]) {
                visited[next] = visited[now] + 1;
                prev[next] = now;
                q.push(next);
            }
        }
    }

    // N == K 인 경우에 실행되지 않아 엣지 케이스 처리가 필요 없음
    for (int i = K; i != N; i = prev[i]) {
        route.push_back(i);
    }
    route.push_back(N);

    std::cout << result - 1 << '\n';
    std::reverse(route.begin(), route.end());

    for (const int n : route) { 
        std::cout << n << ' ';
    }

    return 0;
}
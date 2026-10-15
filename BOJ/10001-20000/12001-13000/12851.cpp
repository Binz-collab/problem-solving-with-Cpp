// 숨바꼭질 2
#include <iostream>
#include <queue>

const int SIZE = 100001;
int visited[SIZE];
long long cnt[SIZE];

int main() {
    int N, K;
    std::cin >> N >> K;

    if (N == K) {
        puts("0");
        puts("1");

        return 0;
    }

    visited[N] = 1;
    cnt[N] = 1;
    std::queue<int> q;
    q.push(N);

    while (q.size()) {
        int now = q.front();
        q.pop();
        for (const int next : { now - 1, now + 1, now * 2 }) {
            if (next < 0 || next >= SIZE) continue;
            if (!visited[next]) {
                q.push(next);
                visited[next] = visited[now] + 1;
                cnt[next] += cnt[now];
            } else if (visited[next] == visited[now] + 1) {
                cnt[next] += cnt[now];
            }
        }
    }

    std::cout << visited[K] - 1 << '\n';
    std::cout << cnt[K] << '\n';

    return 0;
}
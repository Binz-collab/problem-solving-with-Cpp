// 다이어트
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

const int SIZE = 20;
const int INF = 987654321;

struct A {
  int mp, mf, ms, mv, cost;
}a[20];

int min = INF;
std::map<int, std::vector<std::vector<int>>> result_v;

int main() {
    int n;
    std::cin >> n;
    int mp, mf, ms, mv;
    std::cin >> mp >> mf >> ms >> mv;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
    }

    int aa, bb, cc, dd, sum;

    for (int i = 1; i < (1 << n); i++) {
        aa = bb = cc = dd = sum = 0;
        std::vector<int> v;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                v.push_back(j + 1);
                aa += a[j].mp;
                bb += a[j].mf;
                cc += a[j].ms;
                dd += a[j].mv;
                sum += a[j].cost;
            }
        }

        if (aa >= mp && bb >= mf && cc >= ms && dd >= mv) {
            if (min >= sum) {
                min = sum;
                result_v[min].push_back(v);
            }
        }
    }

    if (min == INF) {
        std::cout << -1 << '\n';
    } else {
        std::sort(result_v[min].begin(), result_v[min].end());
        std::cout << min << '\n';
        for (const int n : result_v[min][0]) {
            std::cout << n << ' ';
        }
    }

    return 0;
}

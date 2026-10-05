// 치킨 배달
#include <iostream>
#include <vector>
#include <utility>

const int MAX = 1e9;
const int SIZE = 100;
int a[SIZE][SIZE];
std::vector<std::pair<int, int>> home, chicken;
std::vector<std::vector<int>> chickenList;

int N, M;
int result = MAX;

void combi(int start, std::vector<int> v) {
    if (v.size() == M) {
        chickenList.push_back(v);
        return;
    }

    for (int i = start + 1; i < chicken.size(); i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }

    return;
}

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> a[i][j];
            if (a[i][j] == 1) {
                home.push_back(std::make_pair(i, j));
            }
            if (a[i][j] == 2) {
                chicken.push_back(std::make_pair(i, j));
            }
        }
    }

    std::vector<int> v;
    // "최대" M개의 치킨집을 골라서 거리를 측정하는 거면, 1~M개를 고르는 모든 경우의 수를 만들어봐야 하는 거 아닌감
    combi(-1, v);

    for (const std::vector<int> cList : chickenList) {
        int sum = 0;
        for (const auto h : home) {
            int min = MAX;
            for (int ch : cList) {
                int d = std::abs(h.first - chicken[ch].first) + std::abs(h.second - chicken[ch].second);
                min = std::min(min, d);
            }
            sum += min;
        }
        result = std::min(result, sum);
    }

    std::cout << result << '\n';

    return 0;
}
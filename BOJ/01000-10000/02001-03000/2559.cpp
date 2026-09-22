// 수열
#include <iostream>

// 입력 최대 10만 개 반영해서 여유롭게 설정
const int MAX = 100001;
int psum[MAX];

/**
 * 최댓값 구하기: 최솟값으로 변수 초기화하고 max()로 계속 비교
 * 최솟값 구하기: 최댓값으로 변수 초기화하고 min()으로 계속 비교
 */

int main() {
    int n, k;
    std::cin >> n >> k;
    // 최악의 조합으로 나올 수 있는 최솟값
    int result = -100 * MAX;

    for (int i = 1; i <= n; i++) {
        int temp;
        std::cin >> temp;
        psum[i] = psum[i - 1] + temp;
    }

    // 구간 [p, q]의 합 == 구간 [0, q]의 합 - 구간 [0, p]의 합
    for (int i = k; i <= n; i++) {
        result = std::max(result, psum[i] - psum[i-k]);
    }

    std::cout << result << '\n';

    return 0;
}
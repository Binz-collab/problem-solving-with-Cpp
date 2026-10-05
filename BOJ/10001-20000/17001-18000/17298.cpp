// 오큰수
// 1 ~ 999_999 = 1_000_000 * 1_000_000 / 2 = 5000천억
#include <iostream>
#include <stack>

const int SIZE = 1000001;
int a[SIZE];
int result[SIZE];

std::stack<int> stk;

int main() {
    int N;
    std::cin >> N;

    memset(result, -1, sizeof(result));

    for (int i = 0; i < N; i++) {
        std::cin >> a[i];

        while (!stk.empty() && a[stk.top()] < a[i]) {
            result[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }

    for (int i = 0; i < N; i++) {
        std::cout << result[i] << ' ';
    }

    return 0;
}
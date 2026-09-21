// 곱셈
#include <iostream>

long long a, b, c;

long long go(long long a, long long b) {
    
    if (b == 1) {
        return a % c;
    }

    long long result = go(a, b/2);
    result = (result * result) % c;

    // b가 홀수일 경우 대비
    if (b % 2) {
        result = (result * a) % c;
    }

    return result;
}

int main() {
    std::cin >> a >> b >> c;
    std::cout << go(a, b) << '\n';

    return 0;
}
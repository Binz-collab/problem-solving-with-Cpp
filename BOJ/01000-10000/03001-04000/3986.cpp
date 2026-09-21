// 좋은 단어
#include <iostream>
#include <stack>
#include <string>

int main() {
    int n;
    std::cin >> n;

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        std::stack<char> a;
        for (char c : s) {
            if (!a.empty() && a.top() == c) {
                a.pop();
            } else {
                a.push(c);
            }
        }
        if (a.empty()) {
            cnt++;
        }
    }

    std::cout << cnt << '\n';

    return 0;
}
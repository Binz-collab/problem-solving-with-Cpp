// 괄호
#include <iostream>
#include <stack>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    std::cin >> T;

    std::stack<char> st;

    for (int i = 0; i < T; i++) {
        std::string s;
        std::cin >> s;
        bool flag = false;
        for (const char c : s) {
            if (!st.empty()) {
                if (st.top() == '(' && c == ')') {
                    st.pop();
                    continue;
                }
            }

            if (c == ')') {
                flag = true;
                break;
            }
            // stack이 비어 있는 경우
            // 같은 문자가 들어올 경우
            // 괄호 순서가 안맞게 들어온 경우
            st.push(c);
        }
        // 결과 출력
        if (st.empty() || flag) {
        std::cout << "YES" << '\n';
        } else {
            std::cout << "NO" << '\n';
        }
        // 사용한 스택 초기화
        st = {};
    }

    return 0;
}
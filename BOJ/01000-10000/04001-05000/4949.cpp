// 균형잡힌 세상
#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string s;
    while (true) {
        std::getline(std::cin, s);
        bool flag = true;

        if (s[0] == '.') break;

        std::stack<char> st;
        for (const char c : s) {
            if (c == '(' || c == '[') {
                st.push(c);
            } else if (c == ')' || c == ']') {
                if (st.empty() || (c == ')' && st.top() == '[') || (c == ']' && st.top() == '(')) {
                    flag = false;
                    break;
                }
                st.pop();
            } else {
                continue;
            }
        }

        if (!st.empty()) flag = false;

        if (flag) {
            std::cout << "yes" << '\n';
        } else {
            std::cout << "no" << '\n';
        }

    }
    return 0;
}
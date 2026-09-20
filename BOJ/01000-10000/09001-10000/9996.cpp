// 한국이 그리울 땐 서버에 접속하지
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int N;
    std::string pattern;
    std::cin >> N >> pattern;

    std::string p1 = pattern;
    std::reverse(p1.begin(), p1.end());

    for (int i = 0; i < N; i++) {
        bool isFalse = false;
        int count = 0;

        std::string s;
        std::cin >> s;

        for (int i = 0; i < s.length(); i++) {
            if (pattern[i] == '*') break;

            if (pattern[i] != s[i]) {
                std::cout << "NE" << '\n';
                isFalse = true;
                break;
            }
            count++;
        }

        if (isFalse) continue;
        std::string s1 = s;
        std::reverse(s1.begin(), s1.end());

        for (int i = 0; i < s.length(); i++) {
            if (p1[i] == '*') break;

            if (p1[i] != s1[i]) {
                std::cout << "NE" << '\n';
                isFalse = true;
                break;
            }
            count++;
        }

        if (isFalse || count > s.length()) std::cout << "NE" << '\n';
        else std::cout << "DA" << "\n";
    }

    return 0;
}
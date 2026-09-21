// 농구 경기
#include <iostream>
#include <string>

const int SIZE = 26;
int cnt[SIZE];

int main() {
    int N;
    std::cin >> N;
    
    std::string s;
    for (int i = 0; i < N; i++) {
        std::cin >> s;
        cnt[s[0] - 'a']++;
    }

    std::string result = "";

    for (int i = 0; i < SIZE; i++) {
        if (cnt[i] >= 5) {
            result += char(i + 'a');
        }
    }

    if (result == "") result += "PREDAJA";

    std::cout << result;

    return 0;
}
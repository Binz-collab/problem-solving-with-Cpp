// 수학숙제
#include <iostream>
#include <string>
#include <algorithm>

std::string result;
std::vector<std::string> v;

void go() {
    while (true) {
        // '0' 지우는 로직
        if (result.size() && result.front() == '0') {
            result.erase(result.begin());
        } else break;
    }
    // 다 지워지면 0
    if (result.size() == 0) {
        result = "0";
    }
        v.push_back(result);
        result = "";
};

bool compare(std::string a, std::string b) {
    // 자릿수 -> 사전 순으로 비교
    if (a.size() == b.size()) {
        return a < b;
    }
    
    return a.size() < b.size();
};

int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::string s;
        result = "";
        std::cin >> s;
        for (int j = 0; j < s.size(); j++) {
            // 숫자이면
            if (s[j] < int('A')) {
                result += s[j];
            }
            // 문자열이 비어 있지 않을 때 숫자가 아닌 글자이면 
            else if (result.size()) {
                go();
            }
        }
        // 이건 왜 필요하지?????????????????????
        if (result.size()) {
            go();
        }
    }
    std::sort(v.begin(), v.end(), compare);

    for (std::string s : v) {
        std::cout << s << '\n';
    }

    return 0;
}
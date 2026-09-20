// 나는야 포켓몬 마스터 이다솜
#include <iostream>
#include <string>
#include <map>

std::map<int, std::string> pokebook1;
std::map<std::string, int> pokebook2;

bool isDigit(std::string s) {
    for (char c : s) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        std::cin >> pokebook1[i];
        pokebook2[pokebook1[i]] = i;
    }

    std::string query;
    for (int i = 0; i < M; i++) {
        std::cin >> query;

        // 숫자 판별
        bool isQueryDigit = isDigit(query);
        // 도감 번호 -> 포켓몬 이름
        if (isQueryDigit) {
            std::cout << pokebook1[std::stoi(query)] << '\n';
        }
        // 포켓몬 이름 -> 도감 번호
        else {
            std::cout << pokebook2[query] << '\n';
        } 
    }

    return 0;
}
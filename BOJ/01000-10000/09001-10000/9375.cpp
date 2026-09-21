// 패션왕 신해빈
#include <iostream>
#include <string>
#include <map>

int main() {
    int N;
    std::cin >> N;
    
    for (int i = 0; i < N; i++) {
        int M;
        std::cin >> M;

        std::map<std::string, int> m;
        
        for (int i = 0; i < M; i++) {
            std::string a, b;
            std::cin >> a >> b;
            m[b]++;
        }

        int result = 1;

        for (auto& p : m) {
            result *= (p.second + 1);
        }

        std::cout << result - 1 << '\n';
    }

    return 0;
}
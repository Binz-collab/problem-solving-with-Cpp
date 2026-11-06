// 가르침
#include <iostream>

const int SIZE = 51;
int words[SIZE];

int count(int mask) {
    int cnt = 0;

    for (int word : words) {
        // words 배열에서 유효한 단어를 꺼냈고, 마스크와 전부 일치해야 카운팅 
        if (word && (word & mask) == word) {
            cnt++;
        }
    }

    return cnt;
}

int go(int idx, int k, int mask) {
    if (k < 0) return 0;
    if (idx == 26) return count(mask);

    // idx 번째 알파벳을 배운다.
    int result = go(idx + 1, k - 1, mask | (1 << idx));
    // 'a', 'c', 'i', 'n', 't'를 제외하고
    if (idx != 'a' - 'a' && idx != 'n' - 'a' && idx != 't' - 'a' && idx != 'i' - 'a' && idx != 'c' - 'a') {
        // idx 번째 알파벳을 배우지 않는다.
        result = std::max(result, go(idx + 1, k, mask));
    }

    return result;
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::string s;
    for (int i = 0; i < N; i++) {
        std::cin >> s;
        for (const char str : s) {
            words[i] |= (1 << str - 'a');
        }
    }
    std::cout << go(0, M, 0) << '\n';

    return 0;
}
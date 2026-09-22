// 팰린드롬 만들기
#include <iostream>

const int SIZE = 200;
int cnt[SIZE];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    // 알파벳 ASCII 값에 해당하는 칸에다 카운팅
    for (char c : s) {
        cnt[c]++;
    }

    char mid;
    int flag = 0;
    std::string result;

    for (int i = 'Z'; i >= 'A'; i++) {
        // 이미 카운팅 된 글자에 대해서만 로직 수행
        if (cnt[i]) {
            // 홀수 개 카운팅됐다면
            if (cnt[i] & 1) {
                // 그 글자는 대칭이 안되므로 가운데에 배치해야 함.
                mid = char(i);
                // 홀수 개 나온 숫자 종류 카운팅
                flag++;
                // 가운데 배치했으므로 하나 줄임
                cnt[i]--;
            }

            if (flag > 1) {
                break;
            }
            // 앞뒤로 하나씩 붙임
            for (int j = 0; j < cnt[i]; j += 2) {
                result = char(i) + result;
                result += char(i);
            }
        }
    }

    if (mid) {
        result.insert(result.begin(), result.size() / 2, mid);
    }

    if (flag > 1) {
        std::cout << "I'm Sorry Hansoo" << '\n';
    } else {
        std::cout << result << '\n';
    }

    return 0;
}
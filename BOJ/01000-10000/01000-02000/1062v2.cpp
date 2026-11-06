// 가르침
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

int result, alphabet;
std::map<int, int> cnt;
std::vector<int> v;

bool comp(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }

    return a.second > b.second;
}

int main() {
    int N, K;
    char init[] = { 'a', 'c', 'i', 'n', 't' };

    std::cin >> N >> K;

    if (K >= 5) {
        // prefix + suffix에 무조건 포함되는 글자부터 넣고 시작
        for (const char& c : init) {
            alphabet |= (1 << (int)(c - 'a'));
        }

        K -= 5;

        std::string s;
        for (int i = 0; i < N; i++) {
            std::cin >> s;
            // 중복 글자 제거
            std::set<char> st;   
            for (int j = 0; j < s.size(); j++) {
                st.insert(s[j]);
            }

            int sToi = 0;
            bool flag = false;

            // 없는 글자 카운팅 + 각 단어를 없는 문자 비트로 치환
            for (const char& ch : st) {
                int idx = 1 << (int)(ch - 'a');
                if (!(alphabet & idx)) {
                    cnt[idx] += 1;
                    sToi |= idx;
                    flag = true;
                }
            }

            if (flag) v.push_back(sToi);
            else result++;
        }

        // 카운팅 Map을 Vector로 변환
        std::vector<std::pair<int, int>> v2(cnt.begin(), cnt.end());
        
        // 빈도 수 기준으로 정렬
        std::sort(v2.begin(), v2.end(), comp);

        // 새로운 글자 추가
        for (int i = 0; i < v2.size(); i++) {
            if (K <= 0) break;
            for (int j = 0; j < v.size(); j++) {
                if (v[j] & v2[i].first) {
                    v[j] ^= v2[i].first;
                }
            }
            K--;
        }

        // 읽을 수 있는 단어 추가 카운팅
        result += std::count(v.begin(), v.end(), 0);
    }

    std::cout << result << '\n';

    return 0;
}

// 4글자 이하이면 0
// bool[26]
// for문 돌려서 각 글자를 배웠는지 체크
// 읽을 수 있는 단어 수 카운팅
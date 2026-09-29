// 비밀번호 발음하기
#include <iostream>
#include <string>

bool isVowel(int ascii) {
    return (ascii == 'a' || ascii == 'e' || ascii == 'i' || ascii == 'o' || ascii == 'u');
}


int main() {
    std::string s;
    while (true) {
        std::cin >> s;
        if (s == "end") break;

        int lcnt, vcnt;
        lcnt = vcnt = 0;

        bool flag = false;
        bool is_include_v = false;

        int prev = -1;

        for (int i = 0; i < s.size(); i++) {
            int ascii = s[i];

            if (isVowel(ascii)) {
                lcnt++;
                vcnt = 0;
                is_include_v = 1;
            } 
            
            else {
                vcnt++;
                lcnt = 0;
            }
            // 자음-모음 3개 이상 붙으면 안된다는 조건 체크
            if (vcnt == 3 || lcnt == 3) flag = true;
            // 같은 글자 연달아 사용 금지 조건 체크
            if (i >= 1 && (prev == ascii) && (ascii != 'e' && ascii != 'o')) {
                flag = true;
            }
            // 현재 글자를 다음 루프에 사용할 이전 글자로 저장
            prev = ascii;
        }
        if (!is_include_v) flag = true;
        if (flag) {
            std::cout << '<' << s << '>' << " is not acceptable." << '\n';
        } else {
            std::cout << '<' << s << '>' << " is acceptable." << '\n';
        }
    }

    return 0;
}



// char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
// char consonant[] = { 'b', 'c', 'd', 'f', 'g', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };

// int main() {
//     std::string s;

//     while (s != "end") {
//         bool isAccept = false;
//         std::cin >> s;

//         int len = s.length();

//         // 모음 포함 여부
//         for (const char c : vowels) {
//             if (s.find(c) != std::string::npos) {
//                 isAccept = true;
//                 break;
//             }
//         }

//         // 같은 글자 연속 여부
//         if (isAccept) {
//             for (int i = 0; i < len - 1; i++) {
//                 if (s[i] == s[i+1]) {
//                     if (s[i] != 'e' && s[i] != 'o') {
//                         isAccept = false;
//                         break;
//                     }
//                 } 
//             }
//         }

//         // 3개 연속 여부
//         if (isAccept) {
//             if (len >= 3) {
//                 ???
//             } 
//         }

//         // 출력
//         if (isAccept) {
//             s += " is acceptable.";
//         } else {
//             s += " is not acceptable.";
//         }

//         std::cout << s << '\n';
//     }

//     return 0;
// }
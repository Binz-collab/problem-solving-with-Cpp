// 동전 뒤집기
#include <iostream>
#include <string>

const int SIZE = 22;
const int INF = 987654321;

int map[SIZE];
int min = INF;

int n;

std::string to_binary(int num, int digit) {
	std::string s = "";

    // 1. 하위 digit 자리만 1로 채워진 마스크 생성 
	// (예: digit이 4라면 10000(2) - 1 = 01111(2))
	// 1U는 unsigned int 타입의 1을 의미합니다.
	unsigned int mask = (1U << digit) - 1;
	
	// 2. 마스크를 씌워 앞쪽 32-digit 비트를 모두 0으로 만듦 (음수의 부호 비트도 날아감)
	unsigned int unum = num & mask;

	while (unum > 0) {
		if (unum % 2 == 1) s = "1" + s;
		else s = "0" + s;
		unum >>= 1;
	}

    // 최소 (digit)자리 이상이 될 때까지 앞에 '0'을 추가
	while (s.length() < digit) {
		s = "0" + s;
	}

    // 2진수는 오른쪽부터 체크하므로 결과물 반전
    std::reverse(s.begin(), s.end());

	return s;
}

void go(int here) {
    // base case
    // start ≤ here ≤ n
    if (here == n + 1) {
        for (int i = 1; i <= n; i++) {
            std::cout << to_binary(map[i], n) << '\n';
        }
        std::cout << '\n';

        int sum = 0;
        // i == 0001
        // i == 0010
        // i == 0100
        // i == 1000 (escape)
        for (int i = 1; i <= (1 << (n - 1)); i <<= 1) {
            int cnt = 0;
            // 각 세로줄에 T가 몇 개 있는지 체크
            for (int j = 1; j <= n; j++) {
                if (i & map[j]) cnt++;
            }
            // 현재 상태 cnt와 각 세로줄을 뒤집었을 때의 개수를 비교
            sum += std::min(cnt, n - cnt);
        }
        // 최솟값 비교
        min = std::min(min, sum);
        return;
    }

    // 시행횟수 + 1
    go(here + 1);

    // 행 단위로 동전 뒤집기
    map[here] = ~map[here];
    // 시행횟수 + 1
    go(here + 1);

    // HHT
    // THH
    // THT

    // here == 1
    // 001
    // 100
    // 101

    // here == 2
    // 001 110
    // 100 100
    // 101 101

    // here == 3
    // 001 001 110 110
    // 100 011 100 011
    // 101 101 101 101

    // here == 4
    // 001 001 001 001 110 110 110 110
    // 100 100 011 011 100 100 011 011
    // 101 010 101 010 101 010 101 010
}

int main() {
    std::cin >> n;

    std::string s;
    int start = 1;
    for (int i = start; i <= n; i++) {
        std::cin >> s;
        // 행 단위로 문자열 입력받아서 'T' 인 글자만 마스킹
        int value = 1;
        for (int j = 0; j < s.size(); j++) {
            // std::cout << value << ' ' << s[j] << '\n';
            if (s[j] == 'T') {
                map[i] |= value;
            }
            // value *= 2;
            value <<= 1;
        }
    }

    go(start);

    std::cout << min << '\n';

    return 0;
}
// 다이어트
#include <iostream>
#include <vector>
#include <algorithm>

const int N = 20;
const int INIT = 987654321;

struct Ingridient {
    int a;
    int b;
    int c;
    int d;
    int price;
};

struct Ingridient a[N];
std::vector<int> idx;
int min = INIT;

int main() {
    int n;
    std::cin >> n;

    int aa, bb, cc, dd;
    std::cin >> aa >> bb >> cc >> dd;

    for (int i = 0; i < n; i++) {
        int a1, b1, c1, d1, price;
        std::cin >> a1 >> b1 >> c1 >> d1 >> price;
        a[i] = { a1, b1, c1, d1, price };
    }

    // i = 0 이면 아무것도 없는 상태이므로 i=1 부터 시작해도 됨
    for (int i = 0; i < (1 << n); i++) {
        int tmp[] = { 0, 0, 0, 0, 0 };
        std::vector<int> v;
        // 1 << 0 == 1이므로, j=1 이 아니라 j=0 부터 시작해야 함
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                // 재료 인덱스 값 == j+1
                v.push_back(j + 1);
                tmp[0] += a[j].a;
                tmp[1] += a[j].b;
                tmp[2] += a[j].c;
                tmp[3] += a[j].d;
                tmp[4] += a[j].price;
            }
        }
        if (tmp[0] >= aa && tmp[1] >= bb && tmp[2] >= cc && tmp[3] >= dd) {
            if (tmp[4] == min) {
                // vector 간 부등호 연산 자체가 사전순 비교로 구현되어 있음
                if (v < idx) {
                    // 번호 갱신
                    idx = v;
                }
            }

            if (tmp[4] < min) {
                min = tmp[4];
                // 번호 저장
                idx = v;
            }
        }
    }

    
    if (min == INIT) {
        std::cout << -1 << '\n';
    } else {
        std::cout << min << '\n';

        std::sort(idx.begin(), idx.end());

        for (const int n : idx) {
            std::cout << n << ' ';
        }
    }

    return 0;
}
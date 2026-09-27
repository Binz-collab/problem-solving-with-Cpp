// 쿼드트리
#include <iostream>
#include <set>
#include <string>

const int SIZE = 64;
char map1[SIZE][SIZE];
int map2[SIZE][SIZE];

// start-end 좌표 비교보다 출발점을 start 지점부터 size만큼 이동시키는 게 더 직관적임. 
std::string quad(int y, int x, int size) {
    if (size == 1) return std::string(1, map1[y][x]);

    char c = map1[y][x];
    std::string result = "";
    bool flag = false;

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (c != map1[i][j]) {
                int half = size / 2;
                result += '(';
                result += quad(y, x, half);
                result += quad(y, x + half, half);
                result += quad(y + half, x, half);
                result += quad(y + half, x + half, half);
                result += ')';

                return result;
            }
        } 
    }
    return std::string(1, map1[y][x]);
}

int main() {
    int n;
    scanf("%d", &n);

    char* cp = (char*)malloc(sizeof(char) * (n + 1));

    for (int i = 0; i < n; i++) {
        scanf("%s", cp);
        for (int j = 0; j < n; j++) {
            map1[i][j] = cp[j];
        }
    }

    free(cp);

    printf("%s", quad(0, 0, n).c_str());
    // divideAndConquer(0, 0, n-1, n-1);

    return 0;
}

void divideAndConquer(int sy, int sx, int ey, int ex) {
    std::set<int> st;
    for (int i = sy; i <= ey; i++) {
        for (int j = sx; j <= ex; j++) {
            st.insert(map2[i][j]);
        }
    }

    if (st.size() > 1) {
        int midY = (sy + ey) / 2;
        int midX = (sx + ex) / 2;

        // 영역 분할이 필요하면 괄호 열기
        printf("%c", '(');

        divideAndConquer(sy, sx, midY, midX);
        divideAndConquer(sy, midX + 1, midY, ex);
        divideAndConquer(midY + 1, sx, ey, midX);
        divideAndConquer(midY + 1, midX + 1, ey, ex);

        // 영역 분할이 끝나면 괄호 닫기
        printf("%c", ')');
    } else {
        printf("%d", *st.begin());
    }
}
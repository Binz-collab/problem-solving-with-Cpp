// 경사로
#include <iostream>

const int SIZE = 101;
int result;
int N, L;
int a[SIZE][SIZE], b[SIZE][SIZE];

void go(int p[][SIZE]) {
    for (int i = 0; i < N; i++) {
        // 첫번째 칸은 접근 가능
        int cnt = 1;
        int j;
        for (j = 1; j < N; j++) {
            // 높이가 같을 경우 통과
            if (p[i][j-1] == p[i][j]) {
                cnt++;
            } 
            // 1칸 올라가야할 경우
            // 경사로를 세울 길이가 충분히 있었다면
            else if (p[i][j-1] + 1 == p[i][j] && cnt >= L) {
                // 통과하고 해당 높이에서부터 다시 카운팅
                cnt = 1;
            } 
            // 1칸 내려가야할 경우
            // 다른 내리막 경사로와 겹치지 않는다면
            else if (p[i][j-1] - 1 == p[i][j] && cnt >= 0) {
                // 앞으로 경사로에 필요한 만큼 빼기
                cnt = -L + 1;
            } 
            // 한 번에 2칸 이상 차이나는 경우 || 오르막 경사로를 세울 가로 길이가 부족한 경우 || 내리막 경사로가 겹친 경우 등
            else {
                break;
            }
        }
        // 해당 행을 완주했을 경우에만 카운팅
        if (j == N && cnt >= 0) {
            result++;
        }
    }
}

int main() {
    std::cin >> N >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> a[i][j];
            // 행(가로) 방향으로만 탐색하는 로직 재활용하기 위한 지도 반전
            b[j][i] = a[i][j];
        }
    }

    go(a);
    go(b);

    std::cout << result << '\n';

    return 0;
}
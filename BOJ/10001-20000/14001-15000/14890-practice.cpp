// 경사로
#include <stdio.h>

const int SIZE = 101;
int a[SIZE][SIZE], b[SIZE][SIZE];
int result = 0;
int N, L;

// - -  _ _ _ _
// 1 2 -1 0 1 2

// _ _ _ - - -
// 1 2 3 1 2 3

void solve(int p[][SIZE]) {
    for (int i = 0; i < N; i++) {
        int cnt = 1;
        int j;
        for (j = 0; j < N - 1; j++) {
            // 다음 칸이랑 높이가 같으면 통과
            if (p[i][j] == p[i][j+1]) cnt++;
            // 다음 칸이 한 칸 높으면, 경사로를 놓을 수 있는 밑변 길이가 확보됐으면 통과 && 밑변 길이 초기화
            else if ((p[i][j] + 1 == p[i][j+1]) && (cnt >= L)) cnt = 1;
            // 다음 칸이 한 칸 낮으면, 경사로를 놓는 데 필요한 길이를 미리 덜어냄.
            else if (p[i][j] - 1 == p[i][j+1] && cnt >= 0) cnt = -L + 1;
            // 높이 차이 2 이상 || 경사로 세울 길이 부족 등의 문제가 있으면 중단
            else break;
        }
        // 한 줄 끝까지 다 돌았는데, cnt가 음수가 아니면 완주 처리
        if (j == N - 1 && cnt >= 0) result++;
    }
}

int main() {
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++) {
            scanf("%d", &a[i][j]);
            // 가로 방향 - 세로 방향 모두 대응
            b[i][j] = a[i][j];
        }
    }

    solve(a);
    solve(b);

    printf("%d\n", result);

    return 0;
}
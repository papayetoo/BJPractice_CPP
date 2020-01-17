#include <stdio.h>
#include <cstring>
int G1[101][101], G2[101][101]; // 입력받는 그래프, 출력하는 그래프
int q[10000];
int N;
void bfs(int x) // 그래프 탐색, x ~ 그래프 출발위치
{
    int i, st = -1, ed = 0;
    int chk[101]; // 반복탐색 방지 체크수열
    memset(chk, 0, sizeof(int) * 101);
    q[0] = x; // 탐색 시작점
    while (st != ed) // bfs
    {
        st++;
        for (i = 1; i <= N; i++)
        {
            if (G1[q[st]][i] == 1 && chk[i] != 1) // 현위치의 점과 i번째 점이 연결 && 탐색한적이 없음
            {
                q[++ed] = i; // 큐에 저장
                G2[x][i] = 1; // 출력그래프에 연결정보 저장
                chk[i] = 1; // 한번 들림
            }
        }
    }
}
int main()
{
    int i, j;
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
            scanf("%d", &G1[i][j]);
    }
    for (i = 1; i <= N; i++)
        bfs(i); // 1부터 N까지 호출
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
            printf("%d ", G2[i][j]);
        printf("\n");
    }
}

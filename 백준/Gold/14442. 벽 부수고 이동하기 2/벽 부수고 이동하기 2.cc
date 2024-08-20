#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];
int vis[1001][1001][11];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<tuple<int,int,int>> que;
    int N, M, K;
    string input;
    cin >> N >> M >> K;

    //board 배열 입력받기
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++) {
            board[i][j] = input[j] - '0';
        }
    }

    //맵이 한칸인 경우 연산할거 없이 바로 종료
    if (N == 1 && M == 1) {
        cout << 1;
        return 0;
    }

    //bfs 시작할 큐 넣어주기
    que.push({ 0,0,0 });
    vis[0][0][0] = 1;
    vis[0][0][1] = 1;

    //bfs 진행
    while (!que.empty()) {
        auto cur = que.front(); que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            
            //case 1. 빈칸인 경우 
            if (board[nx][ny] == 0 && vis[nx][ny][get<2>(cur)] == 0) {
                vis[nx][ny][get<2>(cur)] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                que.push({ nx, ny, get<2>(cur) });
            }

            //case 2. 벽을 부숴야 하는 경우
            if (board[nx][ny] == 1 && get<2>(cur) < K && vis[nx][ny][get<2>(cur)+1] == 0) {
                vis[nx][ny][get<2>(cur)+1] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                que.push({ nx,ny,get<2>(cur) + 1 });
            }
        }
    }
    //벽을 부순경우와 안 부수고 간 두가지 경우 중 적게 간 최소거리를 출력
    int ans = 109000000;
    for (int i = 0; i <= K; i++) {
        if (vis[N - 1][M - 1][i] != 0)
            ans = min(ans, vis[N - 1][M - 1][i]);
    }

    if (ans == 109000000) cout << -1;
    else cout << ans;
}

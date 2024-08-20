#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1001][1001];
int vis[1001][1001][2];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<tuple<int,int,int>> que;
    int N, M;
    string input;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++) {
            board[i][j] = input[j] - '0';
        }
    }

    if (N == 1 && M == 1) {
        cout << 1;
        return 0;
    }

    que.push({ 0,0,0 });
    vis[0][0][0] = 1;
    vis[0][0][1] = 1;
    while (!que.empty()) {
        auto cur = que.front(); que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            
            if (board[nx][ny] == 0 && vis[nx][ny][get<2>(cur)] == 0) {
                vis[nx][ny][get<2>(cur)] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                que.push({ nx, ny, get<2>(cur) });
            }

            if (board[nx][ny] == 1 && get<2>(cur) == 0 && vis[nx][ny][1] == 0) {
                vis[nx][ny][1] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                que.push({ nx,ny,1 });
            }
        }
    }
    int ans = 0;
    if (min(vis[N - 1][M - 1][0], vis[N - 1][M - 1][1]) != 0) {
        ans = min(vis[N - 1][M - 1][0], vis[N - 1][M - 1][1]);
    }
    else {
        if (vis[N - 1][M - 1][0] != 0) ans = vis[N - 1][M - 1][0];
        else ans = vis[N - 1][M - 1][1];
    }
    if (ans == 0) cout << -1;
    else cout << ans;
}

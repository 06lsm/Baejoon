#include <bits/stdc++.h>
using namespace std;

unordered_map<int, pair<char, int>> parent;
unordered_map<int, bool> vis;

void BFS(int start, int target) {
    queue<int> q;
    q.push(start);
    vis[start] = true;
    parent[start] = {'\0', -1};

    while (!q.empty() && !vis[target]) {
        int cur = q.front(); q.pop();
        
        // 곱셈
        if (cur <= 31622 && !vis[cur * cur]) { // 31622^2은 약 10^9이므로 overflow 방지
            int next = cur * cur;
            q.push(next);
            vis[next] = true;
            parent[next] = {'*', cur};
        }

        // 덧셈
        if (cur <= 500000000 && !vis[cur + cur]) { // 덧셈으로 overflow 방지
            int next = cur + cur;
            q.push(next);
            vis[next] = true;
            parent[next] = {'+', cur};
        }

        // 뺄셈
        if (cur != 0 && !vis[0]) {
            int next = 0;
            q.push(next);
            vis[next] = true;
            parent[next] = {'-', cur};
        }

        // 나눗셈
        if (cur != 0 && !vis[1]) {
            int next = 1;
            q.push(next);
            vis[next] = true;
            parent[next] = {'/', cur};
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s, t;
    cin >> s >> t;

    //s와 t가 같은 경우
    if (s == t) {
        cout << 0;
        return 0;
    }

    BFS(s, t);

    //바꿀수 없는 경우
    if (!vis[t]) {
        cout << -1;
    } else {
        string result;
        int temp = t;
        while (temp != s) {
            result += parent[temp].first;
            temp = parent[temp].second;
        }
        reverse(result.begin(), result.end());
        cout << result;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> G[1001];
bool vis[1001];

void DFS(int start){
    stack<int> st;
    st.push(start);
    while(!st.empty()){
        auto cur=st.top(); st.pop();
        if(vis[cur]) continue;
        cout << cur << " ";
        vis[cur]=1;
        for(int i=G[cur].size()-1; i>=0; i--){
            if(vis[G[cur][i]]) continue; 
            st.push(G[cur][i]);
        }
    }
}

void BFS(int start){
    queue<int> q;
    q.push(start); 
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        cout << cur << " ";
        vis[cur]=1;
        for(int i=0; i<G[cur].size(); i++){
            if(vis[G[cur][i]]) continue; 
            q.push(G[cur][i]);
            vis[G[cur][i]]=1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, V;
    int num1, num2;
    cin >> N >> M >> V;

    for(int i=0; i<M; i++){
        cin >> num1 >> num2;
        G[num1].push_back(num2);
        G[num2].push_back(num1);
    }

    for (int i = 1; i <= N; i++) {
        sort(G[i].begin(), G[i].end());
    }
    
    DFS(V);
    memset(vis,0,sizeof(vis));
    cout << "\n";
    BFS(V);
}
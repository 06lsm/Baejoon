#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l, num;
    cin >> n >> l;
    vector<int> vec;
    deque<pair<int,int>> dq;
    pair<int,int> pa;
    for(int i=0; i<n; i++){
        cin >> num;
        vec.push_back(num);
    }

    for(int i=0; i<n; i++){
        //first : value, second : order
        pa.first=vec[i];
        pa.second=i;

        //만약 D 범위에 들어가지 않으면 pop하기
        if(dq.front().second < i-l+1) dq.pop_front();

        //deque 뒤에꺼가 지금 넣을려는거보다 크면 빼기
        while(!dq.empty() && dq.back().first > pa.first){
            dq.pop_back();
        }
        dq.push_back(pa);
        cout << dq.front().first << " ";
    }
}
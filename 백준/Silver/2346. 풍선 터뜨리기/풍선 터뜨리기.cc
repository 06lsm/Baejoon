#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    deque<pair<int,int>> dq;
    //first : number, second : order
    pair<int,int> pa;
    int n, num, tt;
    cin >> n;
    //터진 풍선의 번호를 차례로 나열해야하니 처음 순서도 저장함.
    for(int i=0; i<n; i++){
        cin >> pa.first;
        pa.second = i+1;
        dq.push_back(pa);
    }

    //초기값 설정
    pa=dq.front();
    dq.pop_front();
    cout << "1 ";
    while(!dq.empty()){
        //음수면 뒤에꺼 빼서 앞으로 넣음.
        if(pa.first<0){
            for(int i=0; i<abs(pa.first)-1; i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
            pa=dq.back();
            dq.pop_back();
            
        }
        //양수면 앞에꺼 빼서 뒤로 넣음.
        else{
            for(int i=0; i<abs(pa.first)-1; i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
            pa=dq.front();
            dq.pop_front();
        }
        cout << pa.second << " ";
    }
}
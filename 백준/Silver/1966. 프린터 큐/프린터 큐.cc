#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num, n, m, temp;
    cin >> num;

    while(num--){
        queue<int> que;
        int iter=9;
        bool flag = 1;
        int arr[10]={0,};
        cin >> n >> m;
        //입력 받으면서 문서마다 중요도가 뭐 있는지 기록해두기.
        for(int i=0; i<n; i++){
            cin >> temp;
            arr[temp]++;
            que.push(temp);
        }

        while(flag){

            //최대 중요도 문서 없을때
            if(arr[iter]==0){
                iter--;
                if(iter<1) break;
            } 

            //최대 중요도 문서가 que 제일 앞일때 팝
            else if(que.front()==iter){
                que.pop();
                arr[iter]--;
                if(m==0) flag=0;
                else m--;
            } 

            //최대 중요도 문서가 존재하지만 지금 차례가 아닐때 돌리기
            else{
                temp=que.front();
                que.pop(); que.push(temp);
                //맨 앞이면 맨 뒤로
                if(m==0) m=que.size()-1;
                //아니면 한 칸 땡기기
                else m--;
            }
        }
        cout << n-que.size() << "\n";
    }
}
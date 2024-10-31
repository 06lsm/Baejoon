#include <bits/stdc++.h>
using namespace std;

stack<int> st;
stack<int> rst;

int main(){
    int n, num;
    deque<int> v;
    cin >> n;

    //일단 입력 다 받음.
    for(int i=0; i<n; i++){
        cin >> num;
        v.push_back(num);
    }

    //오큰수를 입력받은 반대 수부터 계산함.
    for(int i=0; i<n; i++){

        //자신의 숫자보다 작으면 계속 스택에서 뺌
        while(!st.empty() && st.top()<=v.back()){
            st.pop();
        }
        //만약 비어있으면 -1
        if(st.empty()) rst.push(-1);
        //아니면 그게 오큰수 조건에 부합하는 수
        else rst.push(st.top());

        //오큰수 연산이 끝나면 자기자신의 숫자를 스택에 넣고 다음차례로 넘어감.
        st.push(v.back());
        v.pop_back();
    } 

    for(int i=0; i<n; i++){
        cout << rst.top() << " ";
        rst.pop();
    }
}
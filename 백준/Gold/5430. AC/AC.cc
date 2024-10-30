#include <bits/stdc++.h>
using namespace std;

static deque<int> StringToArr(string arr) {
    deque<int> temp;
    int sum = 0;
    for (char c : arr) {
        if (c == '[' || c == ']') {
            if (c == ']') {
                if(sum!=0)
                    temp.push_back(sum);
            } 
        }
        else if (c == ',') {
            temp.push_back(sum);
            sum = 0;
        }
        else {
            if (sum == 0) sum += c - '0';
            else {
                sum = sum * 10;
                sum += c - '0';
            }
        }
    }
    return temp;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n;
    string p, arr;

    cin >> T; // 테스트 케이스 개수
    while (T--) {
        bool flag = true;
        bool error_flag = false;
        cin >> p; // 수행할 함수
        cin >> n; // 배열의 수 개수
        cin >> arr; // 배열
        deque<int> DQ = StringToArr(arr);
        
        for (char c : p) {
            if (c == 'R') {
                if (flag) {
                    flag = false;
                }
                else {
                    flag = true;
                }
            }

            else{
                if (DQ.empty()) {
                    cout << "error" << "\n";
                    error_flag = true;
                    break;
                }

                else {
                    if (flag) {
                        DQ.pop_front();
                    }

                    else {
                        DQ.pop_back();
                    }
                    --n;
                }
            }
        }

        if (!error_flag && flag) {
            if (n == 0) {
                cout << "[]\n";
            }
            else {
                cout << '[' << DQ.front();
                DQ.pop_front();
                for (int i = 0; i < n - 1; i++) {
                    cout << ',' << DQ.front();
                    DQ.pop_front();
                }
                cout << ']' << "\n";
            }
            
        }
        else if (!error_flag && flag == false) {
            if (n == 0) {
                cout << "[]\n";
            }
            else {
                cout << '[' << DQ.back();
                DQ.pop_back();
                for (int i = 0; i < n - 1; i++) {
                    cout << ',' << DQ.back();
                    DQ.pop_back();
                }
                cout << ']' << "\n";
            }
        }
    }
   

}
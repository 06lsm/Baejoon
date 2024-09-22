#include <bits/stdc++.h>
using namespace std;

bool arr[65][65];

//재귀함수, x,y,는 초기 위치, n은 크기
int F(int x, int y, int n) {
    //압축 초기값
    bool initial = arr[x][y];

    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            //만약 초기값과 다른 값이 있다면 압축을 못함.
            if (arr[i][j] != initial) {
                cout << '(';
                F(x, y, n / 2);
                F(x, y + n / 2, n / 2);
                F(x + n / 2, y, n / 2);
                F(x + n / 2, y + n / 2, n / 2);
                cout << ')';
                return 0;
            }
        }
    }

    cout << initial;
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    string str;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < N; j++) {
            arr[i][j] = str[j] - '0';
        }
    }
    F(0, 0, N);
}
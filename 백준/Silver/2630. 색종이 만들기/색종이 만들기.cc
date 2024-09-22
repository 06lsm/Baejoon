#include <bits/stdc++.h>
using namespace std;

bool arr[128][128];
int blue, white = 0;

//분할정복, x, y는 초기 위치, n은 크기
int divide(int x, int y, int n) {
    bool first = arr[x][y];

    //크기가 한칸이면 잘라내기
    if (n == 1) {
        if (first == 1) blue++;
        else white++;
    }
    //그 이상일 경우 더 자르거나 두기
    else {
        for (int i = x; i < x + n; i++) {
            for (int j = y; j < y + n; j++) {
                //현재 색종이에 다른 색이 있으면 4등분 하기
                if (arr[i][j] != first) {
                    divide(x, y, n / 2);
                    divide(x + n / 2, y, n / 2);
                    divide(x, y + n / 2, n / 2);
                    divide(x + n / 2, y + n / 2, n / 2);
                    return 0;
                }
            }
        }
        //현재 색종이의 색이 다 다같을경우 그 색의 숫자 올리기
        if (first == 1) blue++;
        else white++;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    //크기에 맞춰 색 입력받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    divide(0, 0, N);

    cout << white << "\n" << blue;
}
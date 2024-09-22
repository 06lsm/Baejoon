#include <bits/stdc++.h>
using namespace std;

char arr[2200][2200];

//별찍는 재귀함수, x,y,는 초기 위치, n은 크기
int F(int x, int y, int n) {
    //크기가 3x3이 될때 별찍기
    if (n==3) {
        for (int a = x; a < x + 3; a++) {
            for (int b = y; b < y + 3; b++) {
                if (a == x + 1 && b == y + 1)arr[a][b] = ' ';
                else arr[a][b] = '*';
            }
        }
        return 0;
    }
    F(x,y,n/3); //왼쪽 위
    F(x, y + n /3, n/3); // 왼쪽 중간
    F(x, y + n / 3 * 2, n/3); // 왼쪽 아래
    F(x + n/3, y, n/3); // 중간 위
    F(x + n/3, y + n/3 * 2, n/3); // 중간 아래
    F(x + n/3*2, y, n/3); // 오른쪽 위
    F(x + n / 3 * 2, y + n/3, n/3); // 오른쪽 중간
    F(x + n / 3 * 2, y + n/3*2, n/3); // 오른쪽 아래
    return 0;
}

int main() {
    int N;
    cin >> N;
    F(0, 0, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 0) cout << ' ';
            else cout << arr[i][j];
        }
        cout << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

int val[10];
int N, K, sol = 0, cot=0;

//만약 돈 더했을때 K보다 크면 기각
bool check(int n) {
    if (val[n] + sol > K) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N >> K;

    //나중에 큰 돈부터 더해보기 위해 거꾸로 입력받기
    for (int i = N-1; i >=0; i--) {
        cin >> val[i];
    }

    //개수 최소값 구하기
    while (sol != K) {
        for (int i = 0; i < N; i++) {
            if (check(i)) {
                sol += val[i];
                cot++;
                break;
            }
        }
    }
    cout << cot;
}
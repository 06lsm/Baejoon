#include <bits/stdc++.h>
using namespace std;

int val[1001];
int N, sum=0, rSum=0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }
    sort(val, val + N);
    
    for (int i = 0; i < N; i++) {
        sum += val[i];
        rSum += sum;
    }

    cout << rSum;
}
#include <bits/stdc++.h>
using namespace std;

int arr[500002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M, num;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);  // 배열 정렬
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> num;
        cout << upper_bound(arr, arr+N, num) - lower_bound(arr, arr + N, num)  << ' ';
    }
}
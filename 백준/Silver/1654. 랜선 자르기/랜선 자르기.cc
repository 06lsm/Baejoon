#include <bits/stdc++.h>
using namespace std;

long long int arr[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int K, N;
    long long int mid, num, mx = 0;

    // 랜선 길이 입력
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    long long int left = 1, right = mx; // 탐색 범위 지정
    long long int result = 0;  

    while (left <= right) {
        mid = left + (right - left) / 2;
        long long sum = 0;

        // 랜선 개수 구하기
        for (int i = 0; i < K; i++) {
            sum += arr[i] / mid;
        }

        // 랜선 개수가 충분하면 길이의 최대값을 찾아감
        if (sum >= N) {
            result = mid;  // 가능한 답을 저장
            left = mid + 1;  // 더 긴 길이 탐색
        }
        else {
            right = mid - 1;  // 랜선 개수가 부족하면 더 짧은 길이 탐색
        }
    }

    cout << result;
    return 0;
}
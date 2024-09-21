#include <bits/stdc++.h>
using namespace std;

long long int arr[10000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int H;
    long long int mid, num, mx = 0, M;

    // 나무 길이 입력
    cin >> H >> M;
    for (int i = 0; i < H; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    long long int left = 0, right = mx; // 탐색 범위 지정
    long long int result = 0;  

    while (left <= right) {
        mid = left + (right - left) / 2;
        long long int sum = 0;
            
        // 가져갈 나무 개수 구하기
        for (int i = 0; i < H; i++) {
            if(arr[i] >= mid)
                sum += (arr[i] - mid);
        }

        if (sum == M) {
            cout << mid;
            return 0;
        }

        // 가져갈 나무 길이가 충분하면 절단기 높이 키워봄
        if (sum > M) {
            result = mid;  // 가능한 답을 저장
            left = mid + 1;  // 더 긴 높이 탐색
        }
        else {
            right = mid - 1;  // 더 짧은 높이 탐색
        }
    }

    cout << result;
    return 0;
}
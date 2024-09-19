#include <bits/stdc++.h>
using namespace std;

int arr[100002];

//이진탐색
bool bs(int* arr, int target, int left, int right) {
    if (left > right) return false;  // 탐색 범위가 없으면 false 반환
    int mid = (left + right) / 2;

    if (target == arr[mid]) return true;  // 값을 찾으면 true 반환
    if (target < arr[mid]) return bs(arr, target, left, mid - 1);  // 왼쪽 탐색 
    else return bs(arr, target, mid + 1, right);  // 오른쪽 탐색
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, num;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);  // 배열 정렬
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> num;
        if (bs(arr, num, 0, N - 1))
            cout << "1\n";  // 찾으면 1 출력
        else
            cout << "0\n";  // 못 찾으면 0 출력
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, size[6];
    int sum = 0; // bundle count
    cin >> N;
    for (int i = 0; i < 6; i++) {
        cin >> size[i];
    }

    int T, P;
    cin >> T >> P;

    for (int i = 0; i < 6; i++) {
        if (size[i] % T == 0)
            sum += size[i] / T;
        else
            sum += size[i] / T + 1;

    }

    cout << sum << "\n";

    cout << N / P << " " << N % P;
}
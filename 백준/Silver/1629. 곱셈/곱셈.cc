#include <bits/stdc++.h>
using namespace std;

long long int divide(long long int a,long long int b, long long int c) {
    if (b == 0) return 1;
    
    long long int half = divide(a, b / 2, c);
    half = (half * half) % c;

    if (b % 2 == 0) {
        return half = half % c;
    }
    else {
        return half = half * a % c;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long int A, B, C;
    cin >> A >> B >> C;
    cout << divide(A, B, C);
}
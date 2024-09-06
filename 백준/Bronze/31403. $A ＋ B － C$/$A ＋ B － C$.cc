#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b - c << "\n";

    string A, B;
    A = to_string(a);
    B = to_string(b);
    string AB;
    AB = A + B;
    cout << stoi(AB) - c;
    return 0;
}
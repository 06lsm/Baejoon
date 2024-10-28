#include <bits/stdc++.h>
using namespace std;

void solve() {
    stack<bool> st;
    string str;  cin >> str;
    for (char c : str) {
        if (c == '(') st.push(1);
        else if (st.empty()) {
            cout << "NO\n";
            return;
        }
        else st.pop();
    }
    if (st.empty()) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int num;

    cin >> num;
    while (num--) {
        solve();
    }
}
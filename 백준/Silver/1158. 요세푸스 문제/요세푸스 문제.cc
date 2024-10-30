#include <bits/stdc++.h>
using namespace std;

int arr[5000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    
    list<int> yose;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        yose.push_back(i);
    }

    list<int>::iterator t = yose.begin();
    cout << '<';
    while (yose.size() > 1) {
        for (int i = 0; i < K-1; i++) {
            t++;
            if (t == yose.end()) {
                t = yose.begin();
            }
        }
        cout << *t << ", ";
        t = yose.erase(t);
        if (t == yose.end()) {
            t = yose.begin();
        }
        
    }
    cout << *yose.begin() << '>';
}
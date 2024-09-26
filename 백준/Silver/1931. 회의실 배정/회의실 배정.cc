#include <bits/stdc++.h>
using namespace std;

pair<long int,long int> val[100001];
long int N, cou=0, endN;

//회의 끝나는시간 오름차순
bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

bool compare2(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> val[i].first >> val[i].second;
    }
    sort(val, val + N, compare2);


    //오름차순으로 정리 했기에 일단 처음꺼 이용하기
    endN = val[0].second;
    cou++;

    //현재 이용중인 회의끝나는 시간보다 다음 이용할려는 시간의 first가 크다면 이용하기.
    for (int i = 1; i < N; i++) {
        if (endN <= val[i].first) {
            endN = val[i].second;
            cou++;
        }
    }
    cout << cou;
}
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;
    int order[n]={0,};
    
    for(int i=0; i<n; i++){
        cin >> order[i];
    } 
    sort(order,order+n);
    for(int i=0; i<n; i++){
        cout << order[i] << "\n";
    } 
    return 0;
}
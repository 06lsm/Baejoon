#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int  n; cin >> n;
    int order[1000]={0,};
    int dp[n+2]={0,};
    dp[1]=0;
    
    for(int i=2; i<=n; i++){
        dp[i]=dp[i-1]+1;
        if(i%2==0)dp[i]=min(dp[i],dp[i/2]+1);
        if(i%3==0)dp[i]=min(dp[i],dp[i/3]+1);
    }
    cout << dp[n] << endl;
    
    while(n!=1){
        cout << n << " ";
        if (dp[n]==dp[n-1]+1) n-=1;
        else if(n%2==0 && dp[n]==dp[n/2]+1) n/=2;
        else if(n%3==0 && dp[n]==dp[n/3]+1) n/=3;
    }
    cout << 1;
    return 0;
}

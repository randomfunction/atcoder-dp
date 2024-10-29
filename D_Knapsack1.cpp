#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n,w;
    cin>>n>>w;
    vector<long long> vw(n), vv(n);
    for(long long i=0;i<n;i++){
        cin>>vw[i]>>vv[i];
    }

    //dp array
    vector<vector<long long>> dp(n+1, vector<long long>(w+1,0));
    int prev1;
    int prev2;
    for(long long i=1;i<=n;i++){
        for(long long j=0;j<=w;j++){
            //exclude 
            dp[i][j]=dp[i-1][j];
            int curr= prev1;
            // include if possible
            if(j>=vw[i-1]){
                dp[i][j]= max(dp[i][j], dp[i-1][j-vw[i-1]]+vv[i-1]);
            }
        }
    }

    cout<<dp[n][w]<<endl;
}
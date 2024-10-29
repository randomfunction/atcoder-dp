#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<vector<int>> h(n, vector<int>(3));

    for(int i=0;i<n;i++){
        cin>>h[i][0]>>h[i][1]>>h[i][2];
    }

    vector<vector<int>> dp(n,vector<int>(3,0));

    dp[0][0]= h[0][0];
    dp[0][1]= h[0][1];
    dp[0][2]= h[0][2];

    for(int i=1;i<n;i++){
        dp[i][0]= max(dp[i-1][1], dp[i-1][2]) + h[i][0];
        dp[i][1]= max(dp[i-1][0], dp[i-1][2]) + h[i][1];
        dp[i][2]= max(dp[i-1][0], dp[i-1][1]) + h[i][2];
    }

    int r=max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout<<r<<endl;
}
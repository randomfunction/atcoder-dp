#include<bits/stdc++.h>
using namespace std;
int mod= 1e9+7;

int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> grid(h+1,vector<char>(w+1));
    vector<vector<int>> dp(h, vector<int>(w,0));

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>grid[i][j];
        }
    }

    dp[0][0]=1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(grid[i][j]=='#') dp[i][j]=0;
            else{
                if(i>0) dp[i][j]= (dp[i][j]+dp[i-1][j])%mod;
                if(j>0) dp[i][j]= (dp[i][j]+ dp[i][j-1])%mod;
            }
        }
    }
    cout<<dp[h-1][w-1]<<endl;
}
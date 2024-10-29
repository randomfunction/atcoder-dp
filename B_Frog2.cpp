#include<bits/stdc++.h>

int main(){
    int n,k;
    std::cin>>n>>k;

    std::vector<int> h(n);
    for(int i=0;i<n;i++) std::cin>>h[i];

    //dp array
    std::vector<int> dp(n,INT_MAX);
    dp[0]=0;

    for(int i=1;i<n;i++){
        for(int j=std::max(0,i-k);j<i;j++){
                dp[i]= std::min(dp[i],dp[j]+ abs(h[i]-h[j]));
        }
    }

    std::cout<<dp[n-1]<<std::endl;
}
#include<bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;

    std::vector<int> h(n);
    for(int i=0;i<n;i++) std::cin>>h[i];

    //dp array
    std::vector<int> dp(n,INT_MAX);
    dp[0]=0;
    dp[1]= abs(h[1]-h[0]); 

    for(int i=2;i<n;i++){
        dp[i]= std::min(dp[i-1]+ abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
    }

    std::cout<<dp[n-1]<<std::endl;
}
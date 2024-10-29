#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> dp(k+1,0);
    dp[0]=0; //no stone then losing state
    for(int i=1;i<=k;i++){
        for(auto it :a){
            if(i-it>=0&&dp[i-it]==0){
                dp[i]=1;
                break;
            }
        }
    }

    if(dp[k]) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}
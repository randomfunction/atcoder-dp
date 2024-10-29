#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> graph(n+1);
    vector<int> id(n+1,0);
    vector<int> dp(n+1,0);

    //graph
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        id[y]++;
    }

    //topological sort
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(id[i]==0) q.push(i);
    }

    while(!q.empty()){
        int u= q.front();
        q.pop();

        for(auto v: graph[u]){
            dp[v]=max(dp[v], dp[u]+1);
            id[v]--;
            if(id[v]==0){
                q.push(v);
            }
        }
    }

    int r=0;
    for(int i=1;i<=n;i++){
        r= max(r, dp[i]);
    }    
    cout<<r<<endl;

}
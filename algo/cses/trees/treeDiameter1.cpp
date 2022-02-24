#include<iostream>
#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

int m = (int)1e9 + 7;

void dfs(int u,int par,vi tree[],int dp[],int &ans){
    dp[u]=0;
    for(int v:tree[u]){
        if(v==par)continue;
        dfs(v,u,tree,dp,ans);
    }
    int mx1=0,mx2=0;
    for(int v:tree[u]){
        if(v==par)continue;
        if(mx1<dp[v]){
            mx2=mx1;
            mx1=dp[v];
        }
        else if(dp[v]>mx2){
            mx2=dp[v];
        }
    }
    ans = max(ans,mx1+mx2+1);
    dp[u] = max(dp[u],mx1+1);
}


int32_t main()
{
    int n;
    cin>>n;
    vi tree[n];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        tree[v].pb(u);
        tree[u].pb(v);
    }
    int dp[n];
    int ans = 0;
    dfs(0,-1,tree,dp,ans);
    cout<<ans-1<<endl;
}
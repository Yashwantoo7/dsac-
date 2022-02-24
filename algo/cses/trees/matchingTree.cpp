#include<iostream>
#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

int m = (int)1e9 + 7;

void dfs(int u,int par,vi tree[],int dp[][2]){
    vi prefix,suffix;
    dp[u][0]=dp[u][1] = 0;
    bool leaf = 1;
    for(int v:tree[u]){
        if(v==par)continue;
        leaf = 0;
        dfs(v,u,tree,dp);
    }
    if(leaf)return;
    for(int v: tree[u]){
        if(v!=par){
            prefix.pb(max(dp[v][0],dp[v][1]));
            suffix.pb(max(dp[v][0],dp[v][1]));
        }
    }
    for(int i=1;i<prefix.size();i++){
        prefix[i]+=prefix[i-1];
    }
    for(int i=suffix.size()-2;i>=0;i--){
        suffix[i]+=suffix[i+1];
    }
    dp[u][0] = suffix[0];
    int vNo = 0;
    for(int v:tree[u]){
        if(v==par)continue;
        int l = vNo==0?0:prefix[vNo-1];
        int r = vNo==suffix.size()-1?0:suffix[vNo+1];
        dp[u][1] = max(dp[u][1],1+dp[v][0]+l+r);
        vNo++;
    }
    return ;
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
    int dp[n][2];
    dfs(0,-1,tree,dp);
    // for(int i=0;i<n;i++)cout<<sub[i][0]<<" "<<sub[i][1]<<", ";
    // cout<<endl;
    cout<<max(dp[0][0],dp[0][1])<<endl;
}
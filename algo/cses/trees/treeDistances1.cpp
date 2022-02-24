#include<iostream>
#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

int m = (int)1e9 + 7;

void dfs1(int u,int par,vi tree[],int dp[]){
    dp[u]=0;
    for(int v:tree[u]){
        if(v==par)continue;
        dfs1(v,u,tree,dp);
        dp[u] = max(dp[u],1+dp[v]);
    }
}

void dfs2(int u,int par,vi tree[],int dp[],int parAns,int ans[]){
    vi prefix,suffix;
    for(int v: tree[u]){
        if(v!=par){
            prefix.pb(dp[v]);
            suffix.pb(dp[v]);
        }
    }
    for(int i=1;i<prefix.size();i++){
        prefix[i]=max(prefix[i],prefix[i-1]);
    }
    for(int i=suffix.size()-2;i>=0;i--){
        suffix[i]=max(suffix[i],suffix[i+1]);
    }
    int cnt = 0;
    for(int v:tree[u]){
        if(v!=par){
            int op1 = cnt==0?INT_MIN:prefix[cnt-1];
            int op2 = cnt==suffix.size()-1?INT_MIN:suffix[cnt+1];
            int partialAns = 1+max(parAns,max(op1,op2));
            dfs2(v,u,tree,dp,partialAns,ans);
            cnt++;
        }
    }
    ans[u] = 1+max(parAns,(prefix.empty()?-1:prefix.back()));
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
    int ans[n];
    dfs1(0,-1,tree,dp);
    // for(int i=0;i<n;i++){cout<<dp[i]<<" ";ans[i]=dp[i];}
    // cout<<endl;
    dfs2(0,-1,tree,dp,-1,ans);
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}
#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
 
using namespace std;
 
vi tree[200001];
int par[200001][20];
int lvl[200001];
 
void dfs(int u,int p){
    for(int v:tree[u]){
        if(v==p)continue;
        lvl[v]=lvl[u]+1;
        dfs(v,u);
    }
}
 
void binaryLifting(int u,int p){
    par[u][0]=p;
    for(int i=1;i<20;i++){
        if(par[u][i-1]!=-1){
            par[u][i]=par[par[u][i-1]][i-1];
        }
        else par[u][i]=-1;
    }
    for(int v:tree[u]){
        if(v==p)continue;
        binaryLifting(v,u);
    }
}
 
int lift(int u, int k){
    if(u==-1||k==0)return u;
    for(int i=19;i>=0;i--){
        if(k>=(1<<i)){
            return lift(par[u][i],k-(1<<i));
        }
    }
    return -1;
}
 
int lca(int u,int v){
    if(lvl[u]>lvl[v])swap(u,v);
    v = lift(v,lvl[v]-lvl[u]);
    if(u==v)return u;
    for(int i=19;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u=par[u][i];
            v=par[v][i];
        }
    }
    return lift(u,1);
}
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    binaryLifting(1,-1);
    lvl[1]=0;
    dfs(1,-1);
    // for(int i=1;i<=n;i++)cout<<lvl[i]<<" ";
    // cout<<endl;
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        int x = lca(u,v);
        // cout<<x<<endl;
        cout<<lvl[u]-lvl[x]+lvl[v]-lvl[x]<<endl;
    }
}
 
int32_t main()
{
   solve();
   return 0;
}
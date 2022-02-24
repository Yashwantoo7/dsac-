#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

vi tree[200001];
int par[200001][20];


void binaryLifting(int u,int p){
    par[u][0]=p;
    for(int i=1;i<20;i++){
        if(par[u][i-1]!=-1)
            par[u][i] = par[par[u][i-1]][i-1];
        else par[u][i] = -1;
    }
    for(int v:tree[u]){
        if(v!=p){
            binaryLifting(v,u);
        }
    }
}

int query(int u,int k){
    if(u==-1||k==0)return u;
    for(int i=19;i>=0;i--){
        if(k>=(1<<i)){
            return query(par[u][i],k-(1<<i));
        }
    }
    return -1;
}

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int v;
        cin>>v;
        v--;
        tree[v].pb(i+1);
        tree[i+1].pb(v);
    }
    binaryLifting(0,-1);
    
    for(int i=0;i<q;i++){
        int u,k;
        cin>>u>>k;
        u--;
        int ans = query(u,k);
        if(ans==-1)cout<<ans<<endl;
        else cout<<ans+1<<endl;
    }
}

int32_t main()
{
   solve();
   return 0;
}
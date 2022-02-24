#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

vi tree[200001];
int par[200001][20];
int levels[200001];

void calLevels(int u,int par){
    for(int v:tree[u]){
        if(v==par)continue;
        levels[v]=levels[u]+1;
        calLevels(v,u);
    }
}

void binaryLifting(int u,int p){
    par[u][0]=p;
    for(int i=1;i<20;i++){
        if(par[u][i-1]!=-1){
            par[u][i] = par[par[u][i-1]][i-1];
        }
        else par[u][i]=-1;
    }
    for(int v:tree[u]){
        if(v==p)continue;
        binaryLifting(v,u);
    }
}

int lift(int u,int k){
    if(k==0||u==-1)return u;
    for(int i=19;i>=0;i--){
        if(k>=(1<<i)){
            return lift(par[u][i],k-(1<<i));
        }
    }
    return -1;
}

void lca1(int u,int v){
    if(levels[u]>levels[v])swap(u,v);
    
    v = lift(v,levels[v]-levels[u]);
    if(u==v){
        cout<<u<<endl;
        return;
    }
    int high = levels[u],low=0;
    while(high!=low){
        int mid = (low+high)/2;
        int x1 = lift(u,mid);
        int x2 = lift(v,mid);
        if(x1==x2)high=mid;
        else low = mid+1;
    }
    cout<<lift(u,low)<<endl;
}

void lca2(int u,int v){
    if(levels[u]>levels[v])swap(u,v);
    
    v = lift(v,levels[v]-levels[u]);
    if(u==v){
        cout<<u<<endl;
        return;
    }
    for(int i=19;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u=par[u][i];
            v=par[v][i];
        }
    }
    cout<<lift(u,1)<<endl;
    return;
}

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int v;
        cin>>v;
        tree[i].pb(v);
        tree[v].pb(i);
    }
    binaryLifting(1,-1);
    levels[1]=0;
    calLevels(1,-1);
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        lca2(u,v);
    }
}

int32_t main()
{
    solve();
   return 0;
}
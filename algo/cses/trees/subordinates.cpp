#include<iostream>
#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

int m = (int)1e9 + 7;

int dfs(int u,int par,vi tree[],int sub[]){
    sub[u]=0;
    for(int v:tree[u]){
        if(v==par)continue;
        sub[u]+=dfs(v,u,tree,sub)+1;
    }
    return sub[u];
}


int32_t main()
{
    int n;
    cin>>n;
    vi tree[n];
    for(int i=0;i<n-1;i++){
        int v;
        cin>>v;
        v--;
        tree[v].pb(i+1);
        tree[i+1].pb(v);
    }
    int sub[n];
    dfs(0,-1,tree,sub);
    for(int i=0;i<n;i++)cout<<sub[i]<<" ";
    cout<<endl;
}
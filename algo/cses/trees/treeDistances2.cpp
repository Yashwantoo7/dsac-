#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

vi tree[200001];
int sub[200001];
int subDis[200001];
int ans[200001];

int dfs1(int u,int par){
    sub[u]=0;
    for(int v:tree[u]){
        if(v==par)continue;
        sub[u]+=1+dfs1(v,u);
    }
    return sub[u];
}

int dfs2(int u,int par){
    subDis[u]=sub[u];
    for(int v:tree[u]){
        if(v==par)continue;
        subDis[u]+=dfs2(v,u);
    }
    return subDis[u];
}

void dfs3(int u,int par,int n){
    for(int v:tree[u]){
        if(v==par)continue;
        ans[v]=subDis[v];
        int partialAns = ans[u]-subDis[v]-sub[v]-1;
        ans[v] += n-sub[v]-1;
        ans[v]+=partialAns;
        dfs3(v,u,n);
    }
    return;
}
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs1(0,-1);
    dfs2(0,-1);
    ans[0]=subDis[0];
    dfs3(0,-1,n);
    // for(int i=0;i<n;i++)cout<<subDis[i]<<" ";
    // cout<<endl;
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
   solve();
   return 0;
}
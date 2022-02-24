#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back

using namespace std;

int mod = (int)1e9 + 7;


void dfs(int node,vi graph[], bool vis[]){
    vis[node]=true;
    for(auto n:graph[node]){
        if(vis[n]==false){
            dfs(n,graph,vis);
        }
    }
    return;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vi graph[n+1];
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    
    bool vis[n+1];
    vi nodes;
    memset(vis,false,n+1);
    
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            nodes.pb(i);
            dfs(i,graph,vis);
        }
    }
    if(nodes.size()>=2){
        cout<<nodes.size()-1<<endl;
        for(int i=0;i<nodes.size()-1;i++){
            cout<<nodes[i]<<" "<<nodes[i+1]<<"\n";
        }
    }
    else{
        cout<<0<<"\n";
    }
}

int main()
{
    solve();
   return 0;
}
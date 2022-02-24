#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define ip pair<int,int>

using namespace std;

int mod = (int)1e9 + 7;

int finalAns=INT_MAX;

bool dfs(int node,vi graph[],int colors[]){
    for(int v:graph[node]){
        if(colors[v]==colors[node]){
            return false;
        }
        if(colors[v]==0){
            colors[v]=colors[node]==1?2:1;
            if(!dfs(v,graph,colors)){
                return false;
            }
        }
    }
    return true;
}

void path (vi &parent,int n){
    vi vec;
    while(n>=1){
        vec.pb(parent[n]);
        n=parent[n];
    }
    for(int i=vec.size()-2;i>=0;i--){
        cout<<vec[i]<<" ";
    }cout<<parent.size()-1<<endl;
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
    int colors[n+1];
    for(int i=0;i<n+1;i++)colors[i]=0;
    
    for(int v=1;v<=n;v++){
        if(colors[v]==0){
            colors[v]=1;
            if(!dfs(v,graph,colors)){
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<colors[i]<<" ";
    cout<<endl;
}

int main()
{
    solve();
   return 0;
}
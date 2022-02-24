#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define ip pair<int,int>
#define vb vector<bool>

using namespace std;

int mod = (int)1e9 + 7;

int finalAns=INT_MAX;

bool dfs(int node,int par,vi graph[],vb &vis,vi &path,int &head){
    vis[node]=true;
    for(int v:graph[node]){
       if(vis[v]==false){
           if(dfs(v,node,graph,vis,path,head)){
               if(head!=-1){
                   path.pb(v);
                   if(head==node){path.pb(head);head=-1;}
               }
               return true;
           }
       }
       else if(v!=par){
           head=v;
           path.pb(head);
           return true;
       }
    }
    return false;
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
    vb vis(n+1,false);
    int count=0;
    vi path;
    int head=-1;
    for(int v=1;v<=n;v++){
        if(vis[v]==false){
            if(dfs(v,v,graph,vis,path,head)){
                break;
            }
        }
    }
    if(path.size()>0){
        cout<<path.size()<<"\n";
        for(int i:path)cout<<i<<" ";
        cout<<endl;
    }
    else
        cout<<"IMPOSSIBLE"<<"\n";
}

int main()
{
    solve();
   return 0;
}
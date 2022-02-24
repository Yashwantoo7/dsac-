#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define ip pair<int,int>
#define pq priority_queue<ip,vector<ip>,greater<ip>>
using namespace std;
 
int MX = (int)1e18;
stack <int> order;

bool dfs(int u,vi graph[],bool vis[],stack<int>&stk,bool inStk[]){
    vis[u]=true;
    stk.push(u);
    inStk[u]=true;
    for(int v:graph[u]){
        if(!vis[v]){
            if(!dfs(v,graph,vis,stk,inStk)){
                return false;
            }
            order.push(v);
        }
        if(inStk[v]){
            return false;
        }
    }
    stk.pop();
    inStk[u]=false;
    return true;
}
 
void solve(){
    int n,m;
    cin>>n>>m;
    vi graph[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].pb(b);
    }
    stack<int>stk;
    bool inStk[n+1];
    for(int i=0;i<n+1;i++)inStk[i]=false;
    bool vis[n+1];
    for(int i=0;i<n+1;i++)vis[i]=false;
    for(int u=1;u<=n;u++){
        if(!vis[u]){
            if(!dfs(u,graph,vis,stk,inStk)){cout<<"IMPOSSIBLE";return;}
            order.push(u);
        }
    }
    while(!order.empty()){
        cout<<order.top()<<" ";
        order.pop();
    }
}
 
int32_t main()
{
   solve();
   return 0;
}
// #include <iostream>
// #include <bits/stdc++.h>
// #define int long long
// #define vi vector<int>
// #define pb push_back
// #define ip pair<int,int>
// #define pq priority_queue<ip,vector<ip>,greater<ip>>
// using namespace std;
 
// int MX = (int)1e18;
 
// bool dfs(int u,vi graph[],bool vis[],vi &path){
//     vis[u]=true;
//     path.pb(u);
//     for(int v:graph[u]){
//         if(vis[v]){
//             path.pb(v);
//             return true;
//         }
//         if(dfs(v,graph,vis,path)){
//             return true;
//         }
//     }
//     path.pop_back();
//     vis[u]=false;
//     return false;
// }
 
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vi graph[n+1];
//     for(int i=0;i<m;i++){
//         int a,b;
//         cin>>a>>b;
//         graph[a].pb(b);
//     }
//     vi path;
//     bool vis[n+1];
//     memset(vis,false,sizeof(vis));
//     for(int i=1;i<=n;i++){
//         if(dfs(i,graph,vis,path)){
//             vi vec;
//             int node=path.back();
//             path.pop_back();
//             vec.pb(node);
//             while(path.back()!=node){
//                 vec.pb(path.back());
//                 path.pop_back();
//             }
//             vec.pb(path.back());
//             cout<<vec.size()<<"\n";
//             for(int i=vec.size()-1;i>=0;i--)cout<<vec[i]<<" ";
//             return;
//         }
//     }
//     cout<<"IMPOSSIBLE";
// }
 
// int32_t main()
// {
//   solve();
//   return 0;
// }





#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define ip pair<int,int>
#define pq priority_queue<ip,vector<ip>,greater<ip>>
using namespace std;
 
int MX = (int)1e18;
 
bool dfs(int u,vi graph[],bool vis[],stack<int>&stk,bool inStk[]){
    vis[u]=true;
    stk.push(u);
    inStk[u]=true;
    for(int v:graph[u]){
        if(!vis[v]){
            if(dfs(v,graph,vis,stk,inStk)){
                return true;
            }
        }
        if(inStk[v]){
            stk.push(v);
            return true;
        }
    }
    stk.pop();
    inStk[u]=false;
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
    }
    stack<int>stk;
    bool inStk[n+1];
    for(int i=0;i<n+1;i++)inStk[i]=false;
    bool vis[n+1];
    for(int i=0;i<n+1;i++)vis[i]=false;
    for(int u=1;u<=n;u++){
        if(!vis[u]){
            if(dfs(u,graph,vis,stk,inStk)){
                vi path;
                int node=stk.top();
                stk.pop();
                path.pb(node);
                int count=1;
                while(stk.top()!=node){
                    path.pb(stk.top());
                    stk.pop();
                    count++;
                }
                path.pb(node);
                count++;
                cout<<count<<"\n";
                for(int i=count-1;i>=0;i--)cout<<path[i]<<" ";
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}
 
int32_t main()
{
   solve();
   return 0;
}
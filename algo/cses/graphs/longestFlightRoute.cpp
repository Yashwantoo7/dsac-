
#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define ip pair<int,int>
#define pq priority_queue<ip>
using namespace std;
 
int MX = (int)1e18;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<ip> graph[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].pb({b,1});
    }
    
    int parent[n+1];
    parent[1]=-1;
    pq q;
    q.push({1,1});
    int dist[n+1];
    for(int i=0;i<n+1;i++)dist[i]=0;
    while(!q.empty()){
        ip p=q.top();
        int u=p.second;
        int d=p.first;
        q.pop();
        if(dist[u]>d)continue;
        for(auto e:graph[u]){
            int v=e.first;
            int c=e.second;
            if(dist[v]<c+d){
                dist[v]=c+d;
                q.push({c+d,v});
                parent[v]=u;
            }
        }
    }
    if(dist[n]==0){cout<<"IMPOSSIBLE";return;}
    vi vec;
    int i=n;
    while(i!=-1){
        vec.pb(i);
        i=parent[i];
    }
    cout<<dist[n]<<"\n";
    reverse(vec.begin(),vec.end());
    for(int i:vec)cout<<i<<" ";
}
 
int32_t main()
{
   solve();
   return 0;
}
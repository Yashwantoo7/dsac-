#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

struct edge{
    int u;
    int v;
    int w;
};

int mod = (int)1e9 + 7;

ll INF = (ll)1e17 ;
ll NINF = -1*INF;

void bellmanFord(vector<edge>&edges, ll dist[],int n,int m){
    
    for(int i=1;i<n;i++){
        for(auto edge:edges){
            int u,v,w;
            u=edge.u;
            v=edge.v;
            w=edge.w;
            if(dist[u]==INF)continue;
            dist[v]=min(dist[v],dist[u]+w);
            dist[v]=max(dist[v],NINF);
        }
    }
    for(int i=1;i<n;i++){
        for(auto edge:edges){
            int u,v,w;
            u=edge.u;
            v=edge.v;
            w=edge.w;
            if(dist[u]==INF)continue;
            dist[v]=max(dist[v],NINF);
            if(dist[v]>dist[u]+w)dist[v]=NINF;
        }
    }
    
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<edge>edges;
    for(int i=0;i<m;i++){
        edge e;
        int u,v,w;
        cin>>u>>v>>w;
        e.u=u;e.v=v;e.w=-1*w;
        edges.pb(e);
    }
    
    ll dist[n+1];
    for(int i=2;i<=n;i++)dist[i]=INF;
    dist[1]=0;
    
    bellmanFord(edges,dist,n,m);
    
    if(dist[n]==NINF){
        cout<<-1<<endl;
        return ;
    }
    cout<<dist[n]*(-1)<<endl;
    
}

int main()
{
    solve();
  return 0;
}


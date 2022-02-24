#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define ip pair<int,int>
#define pq priority_queue<ip,vector<ip>,greater<ip>>
using namespace std;

int MX = (int)1e18;



void solve(){
  int n,m,k;
  cin>>n>>m>>k;
  vector<pair<int,int>> graph[n+1];
  for(int i=0;i<m;i++){
      int a,b,c;
      cin>>a>>b>>c;
      graph[a].pb({b,c});
  }
  
  int dist[n+1][k];
  for(int i=0;i<n+1;i++){
      for(int j=0;j<k;j++)dist[i][j]=MX;
  }
  pq q;
  q.push({0,1});
  while(!q.empty()){
      auto p = q.top();
      int u=p.second;
      int d=p.first;
      q.pop();
      if(dist[u][k-1]<d)continue;
      
      for(auto e:graph[u]){
          int v=e.first;
          int c=e.second;
          if(dist[v][k-1]>c+d){
              dist[v][k-1]=c+d;
              q.push({c+d,v});
              sort(dist[v],dist[v]+k);
          }
      }
  }
  for(int i=0;i<k;i++)cout<<dist[n][i]<<" ";
  cout<<"\n";
}

int32_t main()
{
   solve();
   return 0;
}
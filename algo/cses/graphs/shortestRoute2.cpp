#include<iostream>
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int mod = (int)1e9 + 7;

ll mx = (ll)1e17 ;

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    ll graph [n][n];
     
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           graph[i][j]=mx;
       }
   }
   
   for(int i=0;i<m;i++){
       ll a,b,c;
       cin>>a>>b>>c;a--;b--;
       graph[a][b]=min(graph[a][b],c);
       graph[b][a]=graph[a][b];
   }
   
   for(int i=0;i<n;i++)graph[i][i]=0;
   
   for(int k=0;k<n;k++){
       for(int u=0;u<n;u++){
           for(int v=0;v<n;v++){
               graph[u][v]=min(graph[u][v],graph[u][k]+graph[k][v]);
              graph[v][u]=graph[u][v];
           }
       }
   }
//   for(int i=0;i<n;i++){
//       for(int j=0;j<n;j++){
//           cout<<graph[i][j]<<"\t";
//       }cout<<endl;
//   }
   for(int i=0;i<q;i++){
       int u,v;
       cin>>u>>v;u--;v--;
       if(graph[u][v]==mx)cout<<-1<<"\n";
       else cout<<graph[u][v]<<"\n";
   }
}

int main()
{
    solve();
  return 0;
}


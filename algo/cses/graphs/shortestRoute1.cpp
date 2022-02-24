#include <iostream>
// #include <bits/stdc++.h>
// #define ll long long
// #define vi vector<int>
// #define pb push_back
// #define ip pair<ll,ll>
// #define vp vector<pair<int,int>>

// using namespace std;

// int mod = (int)1e9 + 7;

// ll mx = (int)1e19 ;

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vp graph[n+1];
    
//     for(int i=0;i<m;i++){
//         int a,b,c;
//         cin>>a>>b>>c;
//         graph[a].pb({b,c});
//     }
//     priority_queue<ip,vector<ip>,greater<ip>> pq;
    
//     vector<ll> dist(n+1);
//     for(int i=0;i<n+1;i++)dist[i]=mx;
//     dist[1]=0;
    
//     pq.push({0,1});
    
//     bool pro[n+1];
//     memset(pro,false,sizeof(pro));
//     while(!pq.empty()){
//         ip p = pq.top();
//         pq.pop();
//         pro[p.second]=true;
//         for(auto node:graph[p.second]){
//             if(pro[node.first]==false && dist[node.first]>dist[p.second]+node.second){
//                 dist[node.first]=dist[p.second]+node.second;
//                 pq.push({dist[node.first],node.first});
//             }
//         }
//     }
//     for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
//     cout<<endl;
// }

// int main()
// {
//     solve();
//   return 0;
// }


  
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
int n, m;
vector<vector<pair<int,int>>> g;
vector<int> dist;
const int MAXD = 1e17;
 
void dijkstra()
{
	for(int i = 0; i <= n; ++i)
	{
		dist[i] = MAXD;
	}
 
	priority_queue<pair<int,int>, 
	vector<pair<int,int>>, 
	greater<pair<int,int>> > pq;
	dist[1] = 0;
	pq.push({0,1});
	bool pro[n+1];
	memset(pro,false,sizeof(pro));
	
	while(!pq.empty())
	{
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if(pro[u])continue;
		pro[u]=true;
		for(auto e: g[u])
		{
			int v = e.first;
			int c = e.second;
			if(pro[v]==false && dist[v] > c+d)
			{
				dist[v] = c+d;
				pq.push({dist[v], v});
			}
 
		}
	}
 
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	dist.resize(n+1);
	for(auto i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({v,c});
	}
	dijkstra();
	for(int i = 1; i <=n; ++i )
	{
		cout << dist[i] << " ";
	}
}
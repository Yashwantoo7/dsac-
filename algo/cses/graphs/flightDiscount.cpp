#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
const int INF = 9e17; 
int n, m;
vector<vector<pair<int,int>>> g;
vector<int> dist; 
vector<int> disc;
 
void dij()
{
	priority_queue< 
	pair<int, pair<int,int>>, 
	vector<pair<int, pair<int,int>>>,
	greater<pair<int, pair<int,int>>>
	> pq;
	for(int i = 2; i <= n; ++i)
	{
		dist[i] = INF; 
		disc[i] = INF;
	}
	pq.push({0,{1,0}});
 
	while(!pq.empty())
	{
		int d = pq.top().first;
		int u = pq.top().second.first;
		int f = pq.top().second.second;
		pq.pop();
 
		if(f == 1)
		{
			if(disc[u] < d) continue; 
		}
 
		if(f == 0)
		{
			if(dist[u] < d) continue; 
		}
 
		for(auto e: g[u])
		{
			int v = e.first, c = e.second;
			if(f == 0) 
			{
				if(dist[v] > c + d) 
				{
					dist[v] = c+d;
					pq.push({dist[v], {v,0}});
				}
				if(disc[v] > d + c/2) 
				{
					disc[v] = d + c/2;
					pq.push({disc[v], {v,1}});	
				}
			}
 
			if(f==1)
			{
				if(disc[v] > d + c)
				{
					disc[v] = d + c;
					pq.push({disc[v], {v,1}});	
				}
			}
 
		}
	}
 
	cout << disc[n] << endl;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> n >> m;
	g.resize(n+1);
	dist.resize(n+1);
	disc.resize(n+1);
	for(int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({v,c});
	}
 
	dij();
}































##for undirected graph, can skip at most k edges
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 14, maxk = 20;

int n, m, k;
ll d[maxn][maxk];
struct E{
    int u, w;
};
vector<E> g[maxn];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    memset(d, 63, sizeof d);
    d[0][0] = 0;
    set<pair<ll, pair<int, int> > > q({{0, {0, 0}}});
    while(q.size()){
        auto [v, used] = q.begin() -> second;
        q.erase(q.begin());
        auto upd = [&q](int u, int used, ll nw){
            if(used <= k && nw < d[u][used]){
                q.erase({d[u][used], {u, used}});
                d[u][used] = nw;
                q.insert({d[u][used], {u, used}});
            }
        };
        for(auto [u, w] : g[v]){
            upd(u, used, d[v][used] + w);
            upd(u, used + 1, d[v][used]);
        }
    }
    for(int i = 0; i < n; i++)
        cout << *min_element(d[i], d[i + 1]) << ' ';
    cout << '\n';   
}


























#include <bits/stdc++.h>
using namespace std;

typedef int ll;
#define int long long

const int maxn=5e5+5;
vector<pair<int,int> >graph[maxn];

int cost[maxn][20];
bool vis[maxn][20];
int n,m,k;
    
void djkstra() {
    priority_queue<pair<int, pair<int, int> > >pq;
    pq.push(make_pair(0, make_pair(1, 0)));
    cost[1][0]=0;
    while (!pq.empty()) {


        pair<int, pair<int, int> >curr=pq.top();
        pq.pop();
        int curr_n=curr.second.first;
        int curr_s=curr.second.second;
        int cst=cost[curr_n][curr_s];


        for (int i=0; i<graph[curr_n].size(); i++) {
            if(graph[curr_n][i].first==curr_n)  continue;
            int c_cst=cst+graph[curr_n][i].second;
            if(cost[graph[curr_n][i].first][curr_s]==-1) {
                pq.push(make_pair(c_cst*(-1), make_pair(graph[curr_n][i].first, curr_s)));
                cost[graph[curr_n][i].first][curr_s]=c_cst;
            }
            else if(cost[graph[curr_n][i].first][curr_s]>c_cst) {
                cost[graph[curr_n][i].first][curr_s]=c_cst;
                pq.push(make_pair(c_cst*(-1), make_pair(graph[curr_n][i].first, curr_s)));
            }
            c_cst=cst;
            if(curr_s==k)   continue;
            if(cost[graph[curr_n][i].first][curr_s+1]==-1) {
                pq.push(make_pair(c_cst*(-1), make_pair(graph[curr_n][i].first, curr_s+1)));
                cost[graph[curr_n][i].first][curr_s+1]=c_cst;
            }
            else if(cost[graph[curr_n][i].first][curr_s+1]>c_cst) {
                cost[graph[curr_n][i].first][curr_s+1]=c_cst;
                pq.push(make_pair(c_cst*(-1), make_pair(graph[curr_n][i].first, curr_s+1)));
            }
        }


    }
    
    for (int i=1; i<=n; i++) {
        long long ret=2e18;
        for (int j=0; j<=k ; j++) {
            if(cost[i][j]==-1)  continue;
            ret=min(ret,cost[i][j]);
        }
        cout<<ret<<" ";
    }
}

ll main() {
    cin>>n>>m>>k;
    
    for (int i=0; i<m; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    memset(cost,-1,sizeof(cost));
    djkstra();
}
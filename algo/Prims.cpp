/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
#define INF 100000
using namespace std;

int v=5;
int minD(bool vis[],int arr[]){
    int m=INT_MAX;
    int ind=-1;
    for(int i=0;i<v;i++){
        if(vis[i]==false and m>arr[i]){
            m=arr[i];
            ind=i;
        }
    }
    return ind;
}

int mst(int g[][5]){
   
    int dis[v]={0,INF,INF,INF,INF};
    bool vis[v];
    for(int i=0;i<v;i++)vis[i]=false;
    int parent[v]={0};
    parent[0]=-1;
    
    for(int i=0;i<v-1;i++){
        int curr=minD(vis,dis);
        for(int i=0;i<v;i++){
            if(g[curr][i]!=0 and vis[i]==false and g[curr][i]<dis[i]){dis[i]=g[curr][i];parent[i]=curr;}
        }
        vis[curr]=true;
    }
    for(int i=0;i<v;i++){
        cout<<parent[i]<<" ";
    }cout<<endl;
    return 0;
}

int main()
{
    int graph[5][5] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  
    mst(graph);
    return 0;
}




using priority queue

class Solution

{
	public:
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,0});
        int dis[v],par[v];
        for(int i=0;i<v;i++){
            dis[i] = 100000000;
            par[i] = -1;
        }
        dis[0] = 0;
        bool vis[v];
        for(int i=0;i<v;i++)vis[i] = false;
        
       while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int d = p.first, u = p.second;
            for(int j=0;j<adj[u].size();j++){
                if(vis[adj[u][j][0]]==false && dis[adj[u][j][0]]>adj[u][j][1] ){
                    dis[adj[u][j][0]] = adj[u][j][1];
                    par[adj[u][j][0]] = u;
                    pq.push({adj[u][j][1],adj[u][j][0]});
                }
            }
            vis[u]=true;
        }
        // for(int i=0;i<v;i++)cout<<par[i]<<" ";cout<<endl;
        // for(int i=0;i<v;i++)cout<<dis[i]<<" ";cout<<endl;
        int ans = 0;
        for(int i=0;i<v;i++)ans+=dis[i];
        
        return ans;
    }
};

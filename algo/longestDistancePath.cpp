/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include<bits/stdc++.h> 
#include<unordered_map>
#define V 6
#define pb push_back
#include<stack>

using namespace std;

unordered_map<int,vector<pair<int,int>>> adj;

void DFS(int curr,vector<bool>&vis,stack<int>&stk){
    vis[curr]=true;
    for(auto i:adj[curr]){
        if(vis[i.first]==false)
        DFS(i.first,vis,stk);
    }
    stk.push(curr);
}

void LDP(vector<int>&dist,int s){
    vector<bool>vis(V,false);
    stack<int>stk;
    for(int i=0;i<V;i++){
        if(vis[i]==false)
        DFS(i,vis,stk);
    }
    
    dist[s]=0;
    while(!stk.empty()){
        int u=stk.top();
        stk.pop();
        for(auto v:adj[u]){
            if(dist[v.first]<(dist[u]+v.second)){
                dist[v.first]=dist[u]+v.second;
            }
        }
    }
    
    for(auto i:dist){
        cout<<i<<" ";
    }
}

int main()
{   
    adj[0].pb(make_pair(1,5));
    adj[0].pb(make_pair(2,3));
    adj[1].pb(make_pair(3,6));
    adj[1].pb(make_pair(2,2));
    adj[2].pb(make_pair(4,4));
    adj[2].pb(make_pair(5,2));
    adj[2].pb(make_pair(3,7));
    adj[3].pb(make_pair(5,1));
    adj[3].pb(make_pair(4,-1));
    adj[4].pb(make_pair(5,-2));
    
    for(int i=0;i<V;i++){
        for(auto j:adj[i]){
            cout<<j.first<<" "<<j.second<<endl;
        }
    }
    
    vector<int> dist(V,-1000000);
    int source=1;
    LDP(dist,source);
    
    return 0;
}

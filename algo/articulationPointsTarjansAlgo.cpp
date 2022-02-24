/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void DFS(int u,vector<int>g[],vector<int>&disc,vector<int>&low,vector<int>&parent,vector<bool>&art,int n){
    static int t=0;
    disc[u]=low[u]=t;
    t++;
    int children=0;
    for(int v:g[u]){
        if(disc[v]==-1){
            children++;
            parent[v]=u;
            DFS(v,g,disc,low,parent,art,n);
            low[u]=min(low[u],low[v]);
            if(parent[u]==-1 and children>1){
                art[u]=true;
            }
            if(parent[u]!=-1 and low[v]>=disc[u]){
                art[u]=true;
            }
        }
        else if(parent[u]!=v){
            low[u]=min(low[u],disc[v]);
        }
    }
}

vector<int> articulations(vector<int> g[],int n){
    vector<int>disc(n,-1);
    vector<int>low(n,-1);
    vector<int>parent(n,-1);
    vector<bool>art(n,false);
    for(int i=0;i<n;i++){
        if(disc[i]==-1){
            DFS(i,g,disc,low,parent,art,n);
        }
    }
    vector<int>arts;
    for(int i=0;i<n;i++){
        if(art[i])arts.push_back(i);
    }
    return arts;
}

int main()
{
    int n=5;
    std::vector<int> g[n];
    g[0]={1,2,3};
    g[1]={0,2};
    g[2]={0,1};
    g[3]={0,4};
    g[4]={3};
    vector<int>arts=articulations(g,n);
    for(int i:arts){
        cout<<i<<" ";
    }cout<<endl;
    
    return 0;
}

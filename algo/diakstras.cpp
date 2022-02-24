/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int minGraph(int dis[],bool visited[],int v){
    int idx=-1;
    int val=INT_MAX;
    for(int i=0;i<v;i++){
        if(dis[i]<val and visited[i]==false){val=dis[i];idx=i;}
    }
    return idx;
}

int diakstra(vector<pair<int,int>> graph[],int node,int v){
    int dis[v];
    for(int i=0;i<v;i++){
        dis[i]=INT_MAX;
    }
    dis[node]=0;
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    bool processed[v];
    for(int i=0;i<v;i++){
        processed[i]=false;
    }
    for(int i=0;i<v;i++){
        int node=minGraph(dis,visited,v);
        if(node!=-1){
            visited[node]=true;
            processed[node]=true;
            for(auto p:graph[node]){
                if (dis[p.first]>p.second+dis[node] and processed[p.first]==false){
                    dis[p.first]=p.second+dis[node];
                }
            }
        }
    }
    for(int i=0;i<v;i++){
        cout<<dis[i]<<" ";
    }cout<<endl;
    return 0;
}

int main()
{   
    int v=9;
    vector<vector<int>>vec={{0,1,4},{0,7,8},{1,2,8},{1,7,11},{2,8,2},{2,5,4},
                            {2,3,7},{3,4,9},{3,5,14},{4,5,10},{5,6,2},{6,8,6},
                            {6,7,1},{7,8,7}};
    std::vector<pair<int,int>> graph[v];
    for(int i=0;i<vec.size();i++){
        int a,b,w;
        a=vec[i][0];
        b=vec[i][1];
        w=vec[i][2];
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
    for(int i=0;i<v;i++){
        for(auto p:graph[i])cout<<p.first<<" "<<p.second<<endl;
    }
    diakstra(graph,0,v);
    return 0;
}

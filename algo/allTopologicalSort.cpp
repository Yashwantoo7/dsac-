/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void topologicalSortUtil(vector<int> adj[], int indegrees[],bool *visited,int v,vector<int>&res){
    bool flag=false;
    for(int i=0;i<v;i++){
        if(indegrees[i]==0 and !visited[i]){
            for(int j:adj[i]){
                indegrees[j]--;
            }
            visited[i]=true;
            res.push_back(i);
            topologicalSortUtil(adj,indegrees,visited,v,res);
            res.pop_back();
            visited[i]=false;
            for(int j:adj[i]){
                indegrees[j]++;
            }
            flag=true;
        }
    }
    if(!flag)
    {for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }cout<<endl;}
}

void topologicalSort(vector<int> adj[],int v){
    bool* visited=new bool[v];
    int indegrees[v]={0};
    for(int i=0;i<v;i++){
        for(int j:adj[i]){
            indegrees[j]++;
        }
    }
    for(int i=0;i<v;i++)cout<<indegrees[i]<<" ";
    cout<<endl;
    
    for(int i=v-1;i>=0;i--){
        visited[i]=false;
    }
    vector<int> res;
    topologicalSortUtil(adj, indegrees,visited,v,res);
}

int main()
{   
    int v=6;
    vector<int> adj[v]={{},{},{3},{1},{0,1},{0,2}} ;
    
    topologicalSort(adj,v);
    return 0;
}

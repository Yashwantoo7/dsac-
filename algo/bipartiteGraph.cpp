/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include<unordered_map>
#define V 5
#define pb push_back
#include<stack>

using namespace std;

unordered_map<int,vector<int>>adj;

bool DFS(int curr,vector<bool>&vis,int parent,int root,int count){
    vis[curr]=true;

    for(int j:adj[curr]){
        if(vis[j]==false){
            if (!DFS(j,vis,curr,root,count+1)) {
                return false;}
        }
        else if(j==root and (count+1)%2==1 and j!=parent){
            return false;
        }
    }
    vis[curr]=false;
    return true;
}

bool isbipartite(){
    vector<bool>vis(V,false);
    for(int i=0;i<V;i++){
        if(!DFS(i,vis,-1,i,0))
        return false;
    }
    return true;
}


int main()
{   
    
    adj[0].pb(1);
    adj[1].pb(0);
    adj[1].pb(2);
    adj[2].pb(1);
    adj[3].pb(2);
    adj[2].pb(3);
    cout<<"is bipartite "<<isbipartite();

    return 0;
}

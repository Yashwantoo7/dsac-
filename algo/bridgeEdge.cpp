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

using namespace std;

unordered_map<int,vector<int>>adj;

void DFS(int u,vector<int>&disc,vector<int>&low,vector<int>&parent){
    static int time=0;
    disc[u]=low[u]=time;
    time++;
    int children=0;
    for(int v:adj[u]){
        if(disc[v]==-1){ //it is not visited
            children+=1;
            parent[v]=u;
            DFS(v,disc,low,parent);
            low[u]=min(low[u],low[v]);

            if(low[v]>disc[u]){
                cout<<u<<" "<<v<<endl;
            }
        }
        //ignore child to parent edge
        else if(v!=parent[u]){
            low[u]=min(low[u],disc[v]);
        }
    }
}

void findAps_Tarjan(){
    cout<<"bridges are ";
    vector<int>disc(V,-1),low(V,-1),parent(V,-1);

    for(int i=0;i<V;i++){
        if(disc[i]==-1){
            DFS(i,disc,low,parent);
        }
    }
    cout<<endl;

}

int main()
{
    adj[0].pb(2);
    adj[2].pb(0);
    adj[0].pb(3);
    adj[3].pb(0);
    adj[1].pb(0);
    adj[0].pb(1);
    adj[2].pb(1);

    adj[1].pb(2);
    adj[3].pb(4);
    adj[4].pb(3);
    cout<<"dfjkd"<<endl;
    findAps_Tarjan();


    return 0;
}

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include<unordered_map>
#define V 8
#define pb push_back
#include<stack>

using namespace std;

unordered_map<int,vector<int>>adj,rev;

void DFS1(int curr,vector<bool>&vis,stack<int>&stk){
    vis[curr]=true;
    for(int i:adj[curr]){
        if(vis[i]==false){
            DFS1(i,vis,stk);
        }
    }
    stk.push(curr);
}

void DFS2(int curr,vector<bool>&vis){
    cout<<curr<<" ";
    vis[curr]=true;
    for(int i:rev[curr]){
        if(vis[i]==false)
            DFS2(i,vis);
    }
}

void reverse(){
    for(int i=0;i<V;i++){
        for(int j:adj[i]){
            rev[j].pb(i);
        }
    }
}

void findSCCs(){
    stack<int>myStack ;
    
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            DFS1(i,visited,myStack);
        }
    }
    
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    
    reverse();
    
    cout<<"strongly connected components are "<<endl;
    while(!myStack.empty()){
        int curr=myStack.top();
        myStack.pop();
        if(visited[curr]==false){
            DFS2(curr,visited);
            cout<<endl;
        }
    }
    
}

int main()
{
    adj[0].pb(1);
    adj[1].pb(2);
    adj[2].pb(0);
    adj[2].pb(3);
    adj[3].pb(4);
    adj[4].pb(5);
    adj[4].pb(7);

    adj[5].pb(6);
    adj[6].pb(4);
    adj[6].pb(7);
    findSCCs();

    return 0;
}

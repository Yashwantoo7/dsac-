/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void sccUtil(int node,vector<int>g[],vector<int>&disc,vector<int>&low,vector<bool>&inStack,stack<int>&stk,int n,int&count,vector<vector<int>>&vec){
        static int t=0;
        disc[node]=t;
        low[node]=t;
        t++;
        inStack[node]=true;
        stk.push(node);
        
        for(int i:g[node]){
            if(disc[i]==-1){
                sccUtil(i,g,disc,low,inStack,stk,n,count,vec);
                low[node]=min(low[i],low[node]);
            }
            else if(inStack[i]){
                low[node]=min(low[node],disc[i]);
            }
        }
        if(disc[node]==low[node]){
            count++;
            vec.push_back({});
            while(stk.top()!=node){
              vec[count-1].push_back(stk.top());
                inStack[stk.top()]=false;
                stk.pop();
            }
            vec[count-1].push_back(stk.top());
            inStack[stk.top()]=false;
            stk.pop();
            sort(vec.begin(),vec.end());
        }
        return ;
    }
    
    vector<vector<int>> scc(vector<int>g[],int n){
        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        vector<bool>inStack(n,false);
        vector<vector<int>> vec;
        stack<int>stk;
        int count=0;
        
        for(int i=0;i<n;i++){
            if(disc[i]==-1){
                sccUtil(i,g,disc,low,inStack,stk,n,count,vec);
            }
        }
        return vec;
    }

int main()
{   
    int n=7;
    std::vector<int>graph[n] ;
    graph[0]={1};
    graph[1]={2,3};
    graph[2]={};
    graph[3]={4};
    graph[4]={0,5,6};
    graph[5]={2,6};
    graph[6]={5};
   vector<vector<int>> vec=scc(graph,n);
  for(int i=0;i<vec.size();i++){
      for(int j:vec[i]){
          cout<<j<<" ";
      }cout<<endl;
  }
    return 0;
}

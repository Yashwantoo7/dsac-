#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define ip pair<int,int>
#define vb vector<bool>
#define vp vector<pair<int,int>>
#define lp list<pair<int,int>>

using namespace std;

int mod = (int)1e9 + 7;

int finalAns=INT_MAX;

bool dfs(int node,int par,vi graph[],vb &vis,vi &path,int &head){
    vis[node]=true;
    for(int v:graph[node]){
       if(vis[v]==false){
           if(dfs(v,node,graph,vis,path,head)){
               if(head!=-1){
                   path.pb(v);
                   if(head==node){path.pb(head);head=-1;}
               }
               return true;
           }
       }
       else if(v!=par){
           head=v;
           path.pb(head);
           return true;
       }
    }
    return false;
}

bool isValid(int i,int j,int n,int m,string mat[]){
    if(i<0 || j<0 || i>=n || j>=m || mat[i][j]!='.'){
        return false;
    }
    return true;
}

void solve(){
    int n,m;
    cin>>n>>m;
    string mat[n];
    for(int i=0;i<n;i++){
        cin>>mat[i];
    }
    pair<int,int>parent[n][m];
    vector<vi> moves = {{-1,0},{1,0},{0,-1},{0,1}};
    
    
    lp mon,hum;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='M'){
               mon.pb({i,j});
            }
            else if(mat[i][j]=='A'){
                if(i==0||j==0||i==n-1||j==m-1){
                    cout<<"YES"<<endl;
                    cout<<0<<endl;
                    return;}
                    hum.pb({i,j});
            }
        }
    }
    char parent2[n][m];
    memset(parent2,'1',sizeof(parent2));
    bool possible=false;
    int row,col;
    while(true){
        int sz=mon.size();
        for(int i=0;i<sz;i++){
            pair<int,int> p = mon.front();
            for(auto move:moves){
                int x=p.first+move[0];
                int y=p.second+move[1];
                if(isValid(x,y,n,m,mat)){
                    mat[x][y]='M';
                    mon.pb({x,y});
                }
            }
            mon.pop_front();
        }
        sz=hum.size();
        if(sz==0){
            cout<<"NO"<<endl;
            return;
        }
        for(int i=0;i<sz;i++){
            pair<int,int> p = hum.front();
            for(auto move:moves){
                int x=p.first+move[0];
                int y=p.second+move[1];
                if(isValid(x,y,n,m,mat)){
                    mat[x][y]='A';
                    hum.pb({x,y});
                    if(move[0]==1)parent2[x][y]='D';
                    else if(move[0]==-1)parent2[x][y]='U';
                    if(move[1]==1)parent2[x][y]='R';
                    else if(move[1]==-1)parent2[x][y]='L';
                    parent[x][y]={p.first,p.second};
                    if(x==0||x==n-1||y==0||y==m-1){
                        row=x;col=y;
                        possible=true;
                        break;
                    }
                }
            }
            if(possible)break;
            hum.pop_front();
        }
        if(possible)break;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<parent[i][j].first<<","<<parent[i][j].second<<"\t";
    //     }cout<<endl;
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<parent2[i][j]<<"\t";
    //     }cout<<endl;
    // }

    string path="";
    while(parent2[row][col]!='1'){
        path.pb(parent2[row][col]);
        int r=parent[row][col].first;
        int c=parent[row][col].second;
        row=r;col=c;
    }
    cout<<"YES"<<"\n"<<path.length()<<"\n";
    for(int i=path.length()-1;i>=0;i--)cout<<path[i];
    cout<<"\n";
}

int main()
{
    solve();
   return 0;
}
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

struct Edge {
    int l;
    int src,dst;
};

bool cmp(const Edge &e1,const Edge &e2){
    return e1.l<e2.l;
}

int Find(int parent[],int i){
    if(parent[i]==-1)return i;
    return Find(parent,parent[i]);
}

void Union(int parent[],int x,int y){
    parent[y]=x;
}

void kruskals(int g[][5]){
    std::vector<Edge>vec;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(g[i][j]!=0){
                Edge e={g[i][j],i,j};
                g[j][i]=0;
                vec.push_back(e);
            }
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    int parent[v];
    for(int i=0;i<v;i++) parent[i]=-1;
    vector<Edge> mst;
    
    for(int i=0;i<vec.size();i++){
        int x=Find(parent,vec[i].src);
        int y=Find(parent,vec[i].dst);
        if(x!=y){
            Union(parent,x,y);
            mst.push_back(vec[i]);
            cout<<vec[i].src<<" "<<vec[i].l<<" "<<vec[i].dst<<endl;
        }
    }
}
int main()
{
    int graph[5][5] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  
    kruskals(graph);
    return 0;
}



















//??????????????????????????????????????????????????????????????????????????????????????
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int s;
    int d;
    int w;
};

bool comp(Edge a,Edge b){
    return a.w<=b.w;
    }

int Find(int parent[],int i){
    if(parent[i]!=i){
        parent[i]=Find(parent,parent[i]);
    }
    return parent[i];
}

void Union(int parent[],int rnk[],int sr,int de){
    if (rnk[sr]>rnk[de])
    {
        parent[de]=sr;
    }
    else if(rnk[sr]<rnk[de])
        parent[sr]=de;
    else
    {
        parent[sr]=de;
        rnk[de]++;
    }
}

vector<Edge> mst(vector<Edge> &g,int rnk[],int parent[],int v,int edges){
    int sr,de;
    int i=0;
    vector<Edge> m;
    for(auto e:g){
        sr=Find(parent,e.s);
        de=Find(parent,e.d);
        cout<<endl;
        cout<<"("<<e.s<<" "<<sr<<")"<<" "<<"("<<e.d<<" "<<de<<")"<<endl;
        if(sr==de){
            continue;
        }

        Union(parent,rnk,sr,de);
        i++;
        m.push_back(e);
    }
    for (int i=0;i<v;i++){
        cout<<parent[i]<<" ";
    }
    cout<<endl;
    for (int i=0;i<v;i++){
        cout<<rnk[i]<<" ";
    }
    cout<<endl;

    return m;
}

int main()
{
    vector<Edge>g;
    int v;
    cin>>v;
    int edges;
    cin>>edges;
    Edge e;
    for(int i=0;i<edges;i++){
        cin>>e.s>>e.d>>e.w;
        g.push_back(e);
    }

    sort(g.begin(),g.end(),comp);

    for(auto e:g){
        cout<<e.s<<" "<<e.d<<" "<<e.w<<endl;
    }

    int rnk[v];
    for(int i=0;i<v;i++){
        rnk[i]=0;
    }
    int parent[v];
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    vector<Edge> mt;
    mt=mst(g,rnk,parent,v,edges);
    cout<<endl;
    for(auto e:g){
        cout<<e.s<<" "<<e.d<<" "<<e.w<<endl;
    }
//4
//6
//0 1 2 0 2 5 0 3 1 1 2 6 1 3 4 2 3 3
    return 0;
}


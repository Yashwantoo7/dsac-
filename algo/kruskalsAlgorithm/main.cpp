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
        cout<<endl;//
        cout<<"("<<e.s<<" "<<sr<<")"<<" "<<"("<<e.d<<" "<<de<<")"<<endl;//
        if(sr==de){
            continue;
        }

        Union(parent,rnk,e.s,e.d);
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


/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


class Edges{
    public:
        int from;
        int to;
        int cost;
    Edges(int f,int t,int c){
        from=f;
        to=t;
        cost=c;
    }
    Edges(){
        from=0;
        to=0;
        cost=0;
    }
};

int main()
{   int v,e;
    int INF=10000000;
    v=9;
    e=10;
    int arr[3*e]={0,1,1,1,2,1,2,4,1,4,3,-3,3,2,1,1,5,4,1,6,4,5,6,5,6,7,4,5,7,3};
    Edges edges[e];
    int j=0;
    for(int i=0;i<3*e;i=i+3){
        Edges edge(arr[i],arr[i+1],arr[i+2]);
        edges[j]=edge;
        j+=1;
    }
    int dist[v];
    for(int i=0;i<v;i++){
        dist[i]=INF;
    }
    dist[edges[0].from]=0;
    
    for(int ve=0;ve<v-1;ve++){
    for(int i=0;i<e;i++){
            if(dist[edges[i].from]+edges[i].cost<dist[edges[i].to]){
                dist[edges[i].to]=dist[edges[i].from]+edges[i].cost;
                // cout<<edges[i].from<<" "<<edges[i].to<<" "<<dist[edges[i].to]<<endl;
            }
        }
        
    }
    for(int i:dist){
            cout<<i<<" ";
    }
    cout<<endl;
    for(int ve=0;ve<v-1;ve++){
    for(int i=0;i<e;i++){
            if(dist[edges[i].from]+edges[i].cost<dist[edges[i].to]){
                dist[edges[i].to]=dist[edges[i].from]+edges[i].cost;
                // cout<<edges[i].from<<" "<<edges[i].to<<" "<<dist[edges[i].to]<<endl;
            }
        }
        
    }
    for(int i:dist){
            cout<<i<<" ";
    }
    cout<<endl;
 
    

    
    return 0;
}

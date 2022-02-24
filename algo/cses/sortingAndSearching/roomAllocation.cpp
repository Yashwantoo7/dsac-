#include <iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define ip pair<int,int>
#define pb push_back
#define ll long long

using namespace std;

struct gst{
    int arr,dep,ind;
};

bool cmp(const gst & g1,const gst & g2){
    if(g1.arr==g2.arr) return g1.dep<g2.dep;
    return g1.arr<g2.arr;
}

void solve(){
    int n;
    cin>>n;
    gst arra[n],arr2[n];
    for(int i=0;i<n;i++){
        int a,d;
        cin>>a>>d;
        arra[i].arr=a;
        arra[i].dep=d;
        arra[i].ind=i;
        arr2[i]=arra[i];
    }
    sort(arra,arra+n,cmp);
    // for(int i=0;i<n;i++){
    //     cout<<arra[i].arr<<" "<<arra[i].dep<<" "<<arra[i].ind<<endl;
    // }
    priority_queue<ip,vector<ip>,greater<ip>>pq;
    int room=0;
    vi allots(n);
    for(int i=0;i<n;i++){
        if(!pq.empty() && pq.top().first<arra[i].arr){
            ip p = pq.top();
            pq.pop();
            p.first=arra[i].dep;
            allots[arra[i].ind]=p.second;
            pq.push(p);
        }
        else{
            room++;
            allots[arra[i].ind]=room;
            pq.push({arra[i].dep,room});
        }
    }
    cout<<room<<"\n";
    for(int i=0;i<n;i++){
        cout<<allots[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    solve();
   return 0;
}
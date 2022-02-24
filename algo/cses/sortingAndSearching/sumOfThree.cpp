#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define ip pair<int,int>
#define pb push_back
#define ll long long

using namespace std;

bool cmp(const ip &p1,const ip &p2){
    return p1.first<p2.first;
}

void solve(){
    int n,sum;
    cin>>n>>sum;
    vector<ip> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i].first;
        vec[i].second=i+1;
    }
    sort(vec.begin(),vec.end(),cmp);
    
    for(int i=0;i<n-2;i++){
        int x=sum-vec[i].first;
        for(int j=i+1,k=n-1;j<k;){
            while(j<k){
                if((vec[j].first+vec[k].first)<x){
                    j++;
                }
                else if((vec[j].first+vec[k].first)>x){
                    k--;
                }
                else{
                    vi v = {vec[i].second,vec[j].second,vec[k].second};
                    sort(v.begin(),v.end());
                    for(int i:v)cout<<i<<" ";
                    return;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE";
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
   return 0;
}
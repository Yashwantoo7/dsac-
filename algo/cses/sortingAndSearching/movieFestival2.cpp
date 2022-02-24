#include <iostream>
#include <bits/stdc++.h>

using namespace std;


struct movie{
    int st;
    int en;
};

bool cmp(const movie & m1,const movie &m2){
    if(m1.en==m2.en)return m1.st<m2.st;
    return m1.en<m2.en;
}


void solve(){
    int n,k;
    cin>>n>>k;
    movie arr[n];
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr[i].st=a;
        arr[i].en=b;
    }
    
    sort(arr,arr+n,cmp);
    
    multiset<int>mset;
    mset.insert(-1*arr[0].en);
    int ans=1;
    
    for(int i=1;i<n;i++){
        if(mset.lower_bound(-1*arr[i].st)==mset.end()){
            if(mset.size()<k){
                mset.insert(-1*arr[i].en);
                ans++;
                continue;
            }
        }
        else{
            auto it = mset.lower_bound(-1*arr[i].st);
            mset.erase(it);
            mset.insert(-1*arr[i].en);
            ans++;
        }
    }
    cout<<ans;
    
}

int main()
{   
    solve();
   return 0;
}

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct S{
    int val;
    int ind;
};

bool cmp(const S &a,const S &b){
    return a.val<b.val;
}

// bool cmp(const int &a, const int &b){
//     return a<b;
// }

void solve(){
    int n,m;
    cin>>n>>m;
    
    S arr[n];
    S arr2[n];
    
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[i].val=a;
        arr[i].ind=i;
        arr2[i]=arr[i];
    }
    sort(arr2,arr2+n,cmp);
    int ans=1;
    for(int i=0;i<n-1;i++){
        if(arr2[i+1].ind-arr2[i].ind<0){
            ans++;
        }
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        int temp=min(a,b);
        b=max(a,b);
        a=temp;
        
        temp=arr[a].val;
        arr[a].val=arr[b].val;
        arr[b].val=temp;
        
        int v1,v2;
        v1=arr[a].val;
        v2=arr[b].val;
        temp=min(v1,v2);
        v2=max(v1,v2);
        v1=temp;
        v1--;v2--;
        
        int pos1=0,neg1=0,pos2=0,neg2=0;
        
        if(arr2[v1+1].ind-arr2[v1].ind>0)pos1++;
        else neg1++;
        
        if(v1>0){
            if(arr2[v1].ind-arr2[v1-1].ind>0)pos1++;
            else neg1++;
        }
        
        if(v2-1!=v1){
            if(arr2[v2].ind-arr2[v2-1].ind>0)pos1++;
            else neg1++;   
        }
       
        
        if(v2<n-1){
            if(arr2[v2+1].ind-arr2[v2].ind>0)pos1++;
            else neg1++;
        }
        
        temp=arr2[v1].ind;
        arr2[v1].ind=arr2[v2].ind;
        arr2[v2].ind=temp;
        
        if(arr2[v1+1].ind-arr2[v1].ind>0)pos2++;
        else neg2++;
        
        if(v1>0){
            if(arr2[v1].ind-arr2[v1-1].ind>0)pos2++;
            else neg2++;
        }
        
        if(v2-1!=v1){
            if(arr2[v2].ind-arr2[v2-1].ind>0)pos2++;
            else neg2++;
        }
        
        if(v2<n-1){
            if(arr2[v2+1].ind-arr2[v2].ind>0)pos2++;
            else neg2++;
        }
        
        if(pos2>pos1){
            ans-=(pos2-pos1);
        }
        else{
            ans+=(neg2-neg1);
        }
        
        cout<<ans<<endl;
    }
}

int main()
{
    solve();
    return 0;
}

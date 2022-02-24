#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


// ll fun(ll a,ll b){
//     if(b==0 ){
//         return 1;
//     }
//     if(b==1)return a;
    
//     if(b%2==0){
//         ll temp=fun(a,b/2)%m;
//         return (temp*temp)%m;
//     }
//     else{
//         return ((fun(a,1)%m)*(fun(a,b-1)%m))%m;
//     }
// }

ll fun(ll a,ll b,ll m){
    ll result=1;
    while(b>0){
        if(b%2==1)result=(result*a)%m;
        a=(a*a)%m;
        b=b/2;
    }
    return result%m;
}

void solve(){
    int n;
    cin>>n;
    ll m=1e9+7;
    for(int i=0;i<n;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        cout<<fun(a,fun(b,c,m-1),m)<<endl;
    }
}

int main()
{
       solve();

   return 0;
}
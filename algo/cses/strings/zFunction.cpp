#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> zFunction(string s,int n){
    vector<int> z(n);
    z[0] = 0;
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);
        }
        while((i+z[i])<n && (s[i+z[i]]==s[z[i]])){
            ++z[i];
        }
        if((i+z[i]-1)>r){
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    vector<int> vec = zFunction(s,n);
    for(int i:vec){
        cout<<i<<" ";
    }cout<<endl;
}

int32_t main()
{
    solve();
   return 0;
}
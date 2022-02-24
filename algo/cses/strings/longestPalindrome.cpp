#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
    string s;
    cin>>s;
    string temp;
    temp = "$#";
    for(char c:s){
        temp+=c;
        temp+="#";
    }
    temp+="@";
    
    // cout<<temp<<endl;
    
    int n = temp.length();
    
    int p[n];
    memset(p,0,sizeof(p));
    
    int c = 0, r = 0, ansInt = 0, ind = 0;
    string ans = "";
    
    for(int i=1;i<n;i++){
        int mirr = 2*c-i;
        if(i<r){
            p[i] = min(r-i,p[mirr]);
        }
        while(temp[i + p[i] + 1]==temp[i - p[i] - 1])p[i]++;
        if((i+p[i])>r){
            c = i;
            r = i + p[i];
        }
        if(ansInt<p[i]){
            ind = i;
            ansInt = max(ansInt,p[i]);
        }
    }
    // for(int i=0;i<n;i++)cout<<p[i]<<" ";
    // cout<<endl;
    for(int i = ind-ansInt;i<=ind+ansInt;i++){
        if(temp[i]!='#')ans+=temp[i];
    }
    cout<<ans<<endl;
}

int32_t main()
{
   solve();
   return 0;
}
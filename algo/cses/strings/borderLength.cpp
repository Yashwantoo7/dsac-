#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

//approach 1:
// rolling hash -> 0 to n-1 then n-1 to 0

//approach 2: 
//using LPS


int lps[1000001];
int border[1000001];

void calLps(string pat, int m){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i<m){
        if(pat[len]==pat[i]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len==0){
                lps[i] = 0;
                i++;
            }
            else{
                len = lps[len - 1];
            }
        }
    }
}


void solve(){
    string s;
    cin>>s;
    int m = s.length();
    calLps(s,m);
    lps[m]=0;
    int i = m-1;
    while(i>0){
        border[lps[i]]=1;
        i = lps[i]-1;
    }
    for(int i=1;i<=m;i++){
        if(border[i])cout<<i<<" ";
    }
    cout<<endl;
    
}

int32_t main()
{
   solve();
   return 0;
}
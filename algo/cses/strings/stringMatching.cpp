#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

int lps[1000001];

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

void match(string txt, string pat, int n, int m){
    int i = 0, j = 0, ans = 0;
    calLps(pat,m);
    while(i<n){
        if(txt[i]==pat[j]){
            i++;
            j++;
        }
        if(j==m){
            ans++;
            j = lps[j-1];
        }
        
        else if(i<n && pat[j]!=txt[i]){
            if(j==0){
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
    }
    cout<<ans<<endl;
}

void solve(){
    string txt,pat;
    cin>>txt>>pat;
    int n = txt.length();
    int m = pat.length();
    match(txt,pat,n,m);
}

int32_t main()
{
   solve();
   return 0;
}
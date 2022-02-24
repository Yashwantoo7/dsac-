// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// struct Node{
//     char c;
//     int we=0;
//     Node* child[26]={};
// };

// Node* root = new Node();

// void insert(string s){
//     Node* curr = root;
//     for(int i=0;i<s.length();i++){
//         if(curr->child[s[i]-'a']){
//             curr = curr->child[s[i]-'a'];
//         }
//         else{
//             Node* node = new Node();
//             node->c = s[i];
//             curr->child[s[i]-'a'] = node;
//             curr = curr->child[s[i]-'a'];
//         }
//     }
//     curr->we++;
//     return;    
// }

// bool search(string &s,Node* curr,int i,int &n){
//     if(i==n && curr->we>0)return true;
//     if(i>=n)return false;
//     if(curr->child[s[i]-'a'] && search(s,curr->child[s[i]-'a'],i+1,n))return true;
//     return false;
// }

// string reverse(string s){
//     string ans;
//     for(int i = s.length()-1;i>=0;i--)ans+=s[i];
//     return ans;
// }

// void solve(){
//     string s;
//     cin>>s;
//     int n = s.length();
//     int q;
//     cin>>q;
//     while(q){
//         string temp;
//         cin>>temp;
//         insert(temp);
//         q--;
//     }
//     int dp[n+1];
//     memset(dp,0,sizeof(dp));
//     dp[0] = 1;
    
//     int mod = (int)1e9 + 7;
    
//     for(int i=0;i<n;i++){
//         string x ="";
//         for(int j=i;j>=0;j--){
//           if(j>=0)x = s[j] + x;
//           Node * curr = root;
//           int len = i-j+1;
//         //   cout<<j<<" "<<i<<" "<<x<<endl;
//             if(dp[j] && search(x,curr,0,len))
//                 {dp[i+1] = (dp[j] + dp[i+1])%mod;
//                     // cout<<i+1<<endl;
//                 }
//         }
//     }
//     // for(int i=0;i<=n;i++)cout<<dp[i]<<" ";
//     cout<<dp[n]<<endl;
// }

// int main()
// {
//   solve(); 
//   return 0;
// }



















#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

int trie[1000001][26];
int endWord[1000001];
int counter = 0;
int dp[5005];
int mod = (int)1e9 + 7;

void insert(string s){
    int curr = 0;
    for(char c:s){
        if(trie[curr][c-'a']==0)trie[curr][c-'a'] = ++counter;
        curr = trie[curr][c-'a'];
    }
    endWord[curr] = 1;
}


void solve(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        insert(x);
    }
    int m = s.length();
    dp[m] = 1;
    for(int i=m-1;i>=0;i--){
        int curr = 0; dp[i] = 0;
        for(int j = i;j<m;j++){
            if(trie[curr][s[j]-'a']==0)break;
            curr = trie[curr][s[j]-'a'];
            if(endWord[curr])
            dp[i] = (dp[i]%mod + dp[j+1]%mod)%mod;
        }
    }
    cout<<dp[0]<<endl;
}

int32_t main()
{
   solve();
   return 0;
}
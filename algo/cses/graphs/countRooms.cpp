#include <iostream>
#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int mod = (int)1e9 + 7;

void countRooms(string mat[],int i,int j,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m || mat[i][j]=='#')return;
    mat[i][j]='#';
    countRooms(mat,i+1,j,n,m);
    countRooms(mat,i,j+1,n,m);
    countRooms(mat,i-1,j,n,m);
    countRooms(mat,i,j-1,n,m);
    
    return;
}

void solve(){
    int n,m;
    cin>>n>>m;
    string mat[n];
    for(int i=0;i<n;i++){
        cin>>mat[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='.'){
                ans++;
                countRooms(mat,i,j,n,m);
            }
        }
    }
    cout<<ans<<endl;
    return;
}

int main()
{
    solve();
    return 0;
}

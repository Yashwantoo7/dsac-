/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int mod=(int)1e9 +7;

void solve(){
    int n;
    cin>>n;
    
    int mat[n][n];
    string s;
    cin>>s;
    s[0]=='.'?mat[0][0]=1:mat[0][0]=0;
    for(int i=1;i<n;i++){
        if(s[i]=='.')
        mat[0][i]=mat[0][i-1];
        else mat[0][i]=0;
    }
    for(int i=1;i<n;i++){
        cin>>s;
        s[0]=='.'?mat[i][0]=mat[i-1][0]:mat[i][0]=0;
        for(int j=1;j<n;j++){
            if(s[j]=='.')
            mat[i][j]=(mat[i-1][j]+mat[i][j-1])%mod;
            else mat[i][j]=0;
        }
    }
    // for(int i=0;i<n;i++){for(int j=0;j<n;j++)cout<<mat[i][j]<<"\t";cout<<endl;}
    cout<<mat[n-1][n-1]<<endl;
}

int main()
{
    solve();
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int extendedEuc(int a,int b,int &x,int &y){
    if(a==0){
        x=0;
        y=1;
        return b;
    }
    int x1,y1;
    int ans = extendedEuc(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return ans;
}

void findSol(int a,int b,int c){
    int x,y,g;
    g=extendedEuc(a,b,x,y);
    
    if(c%g){
        cout<<"No solution"<<"\n";
    }
    else{
        x=x*(c/g);
        y=y*(c/g);
        if(a<0)x=-x;
        if(b<0)y=-y;
        cout<<x<<" "<<y<<"\n";
    }
}

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    findSol(a,b,c);
}

int main()
{
   solve();
   return 0;
}
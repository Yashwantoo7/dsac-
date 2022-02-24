/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool fill(pair<int,int>&j1,pair<int,int>&j2,int t,unordered_set<string>&set){
    
    int j1f=j1.second;
    int j1c=j1.first;
    int j2f=j2.second;
    int j2c=j2.first;
    
    if(j1f==t or j2f==t){return true;}
    
    string k=to_string(j1f)+"*"+to_string(j2f);
    if(set.find(k)!=set.end()){
        return false;
    }
    set.insert(k);
    // cout<<j1f<<" "<<j2f<<endl;
    
    int temp1=0,temp2=0;
    pair<int,int>p1,p2;
    
     //filling 1st jug 
    p1=make_pair(j1c,j1c),p2=make_pair(j2c,j2f);
    if(fill(p1,p2,t,set)){cout<<j1c<<" "<<j2f<<endl;return true;}
    
    //filling 2nd jug 
    p1=make_pair(j1c,j1f),p2=make_pair(j2c,j2c);
    if(fill(p1,p2,t,set)){cout<<j1f<<" "<<j2c<<endl;return true;}
    
    //adding to 1st jug 
    temp1=min(j1c,j1f+j2f);
    temp2=j2f-(temp1-j1f);
    p1=make_pair(j1c,temp1),p2=make_pair(j2c,temp2);
    if(fill(p1,p2,t,set)){cout<<temp1<<" "<<temp2<<endl;return true;}
    
    //adding to 2nd jug
    temp2=min(j2c,j2f+j1f);
    temp1=j1f-(temp2-j2f);
    p1=make_pair(j1c,temp1),p2=make_pair(j2c,temp2);
    if(fill(p1,p2,t,set)){cout<<temp1<<" "<<temp2<<endl;return true;}
    
    //empty 1st jug 
    p1=make_pair(j1c,0),p2=make_pair(j2c,j2f);
    if(fill(p1,p2,t,set)){cout<<0<<" "<<j2f<<endl;return true;}
    
    //empty 2nd jug 
    p1=make_pair(j1c,j1f),p2=make_pair(j2c,0);
    if(fill(p1,p2,t,set)){cout<<j1f<<" "<<0<<endl;return true;}
    
    return false;
}

int main()
{
   int jug1=5,jug2=3,target=4;
   pair<int,int> p1=make_pair(jug1,0),p2=make_pair(jug2,0);
   unordered_set<string>set;
   fill(p1,p2,target,set);
   cout<<0<<" "<<0<<endl;
    return 0;
}

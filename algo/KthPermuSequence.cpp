/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findFirstIndex(int &k,int n){
    if(n==1) return 0;
    n--;
    
    int firstIndex;
    int nPartialFact=n;
    while(k>=nPartialFact && n>1){
        nPartialFact=nPartialFact*(n-1);
        n--;
    }
    
    firstIndex=k/nPartialFact;
    k=k%nPartialFact;
    return firstIndex;
}

string findKthPermutation(int n,int k){
    string ans="";
    
    set<int> s;
    
    for(int i=1;i<=n;i++) s.insert(i);
    
    set<int>::iterator itr;
    
    itr=s.begin();
    
    k=k-1;
    
    for(int i=0;i<n;i++){
        int index=findFirstIndex(k,n-i);
        advance(itr,index);
        ans+=(to_string(*itr));
        s.erase(itr);
        itr=s.begin();
    }
    return ans;
}

int main()
{
    int n=3,k=4;
    string kthPermSeq=findKthPermutation(n,k);
    cout<<kthPermSeq<<endl;
    
    return 0;
}

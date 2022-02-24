/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct S{
    int val;
    int ind;
};

bool cmp(const S &a,const S &b){
    return a.val<b.val;
}

// bool cmp(const int &a, const int &b){
//     return a<b;
// }

void solve(){
    int n,x;
    cin>>n>>x;
    S arr[n];
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[i]={a,i};
    }
    sort(arr,arr+n,cmp);
    int i=0,j=n-1;
    while(i<j){
        if(arr[i].val+arr[j].val==x){
            if(arr[i].ind>arr[j].ind)cout<<arr[j].ind+1<<" "<<arr[i].ind+1<<endl;
            else cout<<arr[i].ind+1<<" "<<arr[j].ind+1<<endl;
            return;
        }
        else if(arr[i].val+arr[j].val>x){
            j--;
        }
        else{
            i++;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    
}

int main()
{
    solve();
    return 0;
}

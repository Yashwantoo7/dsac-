/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


// vector<vector<int> > fourSum(vector<int> &arr, int k) {
//     // Your code goes here
//     vector<vector<int>> vec;
    
//     sort(arr.begin(),arr.end());
//     int n=arr.size();
    
//     for (int i = 0; i < n - 3; i++) 
//     {  
//         if(arr[i]>0 and arr[i]>k) break;
//         if(i>0 and arr[i]==arr[i-1]) continue;
        
//         for (int j = i+1; j < n - 2; j++)  
//         {  
//             // Initialize two variables as  
//             // indexes of the first and last  
//             // elements in the remaining elements  
//             if(j>i+1 and arr[j]==arr[j-1]) continue;
//             int l = j + 1;  
//           int  r = n-1;  
  
//             // To find the remaining two  
//             // elements, move the index  
//             // variables (l & r) toward each other.  
//             while (l < r)  
//             {   int oldL=l;
//                 int oldR=r;
                
//                 if( arr[i] + arr[j] + arr[l] + arr[r] == k)  
//                 {  
//                     vector<int>subVec={arr[i],arr[j],arr[l],arr[r]};
//                     vec.push_back(subVec);
//                     while(l<r and arr[l]==arr[oldL]) l++;
//                     while(l<r and arr[r]==arr[oldR]) r--;
                    
//                 }  
//                 else if (arr[i] + arr[j] + arr[l] + arr[r] < k)  
//                     l++;  
//                 else // A[i] + A[j] + A[l] + A[r] > X  
//                     r--;  
//             } // end of while  
//         } // end of inner for loop  
//     }
    
//     return vec;
// }

vector<vector<int> > fourSum(vector<int> &arr, int k) {
    // Your code goes here
    vector<vector<int>> vec;
    
    sort(arr.begin(),arr.end());
    int n=arr.size();
    
    unordered_map <int,pair<int,int>> map;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            map[arr[i]+arr[j]].first=i;
            map[arr[i]+arr[j]].second=j;
        }
    }
    
    int temp[n]={0};
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int currSum=arr[i]+arr[j];
            if(map.find(k-currSum)!=map.end()){
                pair<int,int> p=map[k-currSum];
                if(p.first!=i and p.first!=j and p.second!=i and p.second!=j and 
                !(temp[i]==1 and temp[j]==1 and temp[p.first]==1 and temp[p.second]==1)){
                    vector<int> subVec={arr[i],arr[j],arr[p.first],arr[p.second]};
                    vec.push_back(subVec);
                    temp[i]=1;temp[j]=1;temp[p.first]=1;temp[p.second]=1;
                    break;
                }
            }
        }
    }
    
    for(auto v:vec){
        for(int i:v) cout<<i<<" ";
        cout<<endl;
    }
    return vec;
}

int main(){
    vector<int>vec={10,2,3,4,8,7,8};
    int k=23;
    fourSum(vec,k);
    
   return 0;
}

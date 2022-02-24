
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(const vector<int>& v, int i) 
{ 
    for (int j=i; j<v.size(); j++) 
        cout << v[j] << " "; 
    cout << endl; 
} 
  
// binary tree node 
struct Node 
{ 
    int data; 
    Node *left,*right; 
    Node(int x) 
    { 
        data = x; 
        left = right = NULL; 
    } 
}; 

void printPaths(Node * root,int k,vector<int>&vec){
    if(root==NULL) return ;
    vec.push_back(root->data);
    printPaths(root->left,k,vec);
    printPaths(root->right,k,vec);
    
    
    int f=0;
    for(int i=vec.size()-1;i>=0;i--){
        f+=vec[i];
        if(f==k){
            printVector(vec,i);
        }
    }
    vec.pop_back();
    
}

int main()
{   
    vector<int> vec;
    Node *root = new Node(1); 
    root->left = new Node(3); 
    root->left->left = new Node(2); 
    root->left->right = new Node(1); 
    root->left->right->left = new Node(1); 
    root->right = new Node(-1); 
    root->right->left = new Node(4); 
    root->right->left->left = new Node(1); 
    root->right->left->right = new Node(2); 
    root->right->right = new Node(5); 
    root->right->right->right = new Node(2); 
  
    int k = 5; 
    printPaths(root,k,vec);
    
    return 0; 
}

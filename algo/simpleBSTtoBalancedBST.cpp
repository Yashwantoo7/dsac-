/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <bits/stdc++.h>
#include <iostream>

#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left,*right;
};


void storeBSTNodes(Node* root,vector<Node*>&nodes){
    if(root==NULL)return;
    
    storeBSTNodes(root->left,nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right,nodes);
}

Node * buildTreeUtil(vector<Node*> &nodes,int start,int end){
    if(start>end) return NULL;
    
    int mid=(start+end)/2;
    Node* root=nodes[mid];
    
    root->left=buildTreeUtil(nodes,start,mid-1);
    root->right=buildTreeUtil(nodes,mid+1,end);
    return root;
}

Node* buildTree(Node* root){
    vector<Node*> nodes;
    storeBSTNodes(root,nodes);
    int n=nodes.size();
    return buildTreeUtil(nodes,0,n-1);
}

Node* newNode(int data){
    Node* node=new Node;
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

void preOrder(Node* node){
    if(node==NULL) return;
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}
int main() 
{ 
    /* Constructed skewed binary tree is 
                10 
               / 
              8 
             / 
            7 
           / 
          6 
         / 
        5   */
  
    Node* root = newNode(10); 
    root->left = newNode(8); 
    root->left->left = newNode(7); 
    root->left->left->left = newNode(6); 
    root->left->left->left->left = newNode(5); 
  
    root = buildTree(root); 
  
    cout<<"Preorder traversal of balanced BST is : \n"<<endl; 
    preOrder(root); 
  
    return 0; 
} 

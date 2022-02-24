/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Node{
  public:
    int data;
    Node * left;
    Node * right;
 };
 
 Node * newNode(int d){
     Node *node=new Node();
     node->data=d;
     node->left=node->right=NULL;
     return node;
 }
 
 Node * util(int pre[],int * preIndx,int key,int min,int max,int size){
     if(*preIndx>=size){
         return NULL;
     }
     Node * root=NULL;
     if(key>min && key<max){
         root=newNode(key);
         *preIndx+=1;
         if(*preIndx<size){
             root->left=util(pre,preIndx,pre[*preIndx],min,key,size);
         }
         if(*preIndx<size){
             root->right=util(pre,preIndx,pre[*preIndx],key,max,size);
         }
     }
     return root;
 }


Node* constructTree(int pre[],int size){
    int preIndx=0;
    return util(pre,&preIndx,pre[0],INT_MIN,INT_MAX,size);
}


void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
int main()
{
    int pre[] = { 10, 5, 1, 7, 40, 50 };
    int size = sizeof(pre) / sizeof(pre[0]);
 
    // Function call
    Node* root = constructTree(pre, size);
 
    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);
 
    return 0;
}

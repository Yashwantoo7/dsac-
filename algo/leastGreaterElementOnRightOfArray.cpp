/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode(int item)
{
    Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
 
    return temp;
}
void insert(Node*& root,int data,Node*&succ){
    if(root==NULL) root=newNode(data);
    
    
    if(data<root->data){
        succ=root;
        insert(root->left,data,succ);
    }
    
    else if(root->data<data){
        insert(root->right,data,succ);
    }
}

void lge(int arr[],int n){
    Node * root=NULL;
    for(int i=n-1;i>=0;i--){
        Node * succ=NULL;
        insert(root,arr[i],succ);
        if(succ) arr[i]=succ->data;
        else arr[i]=-1;
    }
}

int main()
{   
    int arr[]={8, 58, 71, 18, 31, 32, 63, 92, 
         43, 3, 91, 93, 25, 80, 28};
    int n=sizeof(arr)/sizeof(arr[0]);
    lge(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}

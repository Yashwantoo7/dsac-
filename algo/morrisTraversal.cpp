/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Node{
  public:
  int data;
  Node * left;
  Node * right;
  Node(){
      data=0;
      left=NULL;
      right=NULL;
  }
};

void MorrisTraversal(Node *root){
    Node* current=root;
    while(current!=NULL){
        if(current->left==NULL){
            cout<<current->data<<endl;
            current=current->right;
        }
        else{
            Node* predecessor=current->left;
            while(predecessor->right!=NULL and predecessor->right!=current){
                predecessor=predecessor->right;
            }
            if(predecessor->right==NULL){
                predecessor->right=current;
                current=current->left;
            }
            else{
                cout<<current->data<<endl;
                predecessor->right=NULL;
                current=current->right;
            }
        }
    }
}

int main()
{   

    return 0;
}

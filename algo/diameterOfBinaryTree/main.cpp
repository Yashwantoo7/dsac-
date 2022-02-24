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

int * maxDia(Node* node){
    if (node==NULL){
        int arr[2]={0,0};
        int *ptr=arr;
        return ptr;
    }
    int *left=maxDia(node->left);
    int *right=maxDia(node->right);

    int ans[2]={max(*left,*(right))+1,max(max(*(left+1),*(right+1)),1+*(left)+*(right))};
    int *ptr=ans;
    return ptr;
}

int diameter(Node* node) {
    // Your code here
    int *ptr=maxDia(node);
    return max(*ptr,*(ptr+1));

}
int main()
{
    Node *node=new Node();
    node->data=1;

    Node *l=new Node();
    l->data=2;

    node->left=l;

    Node *r=new Node();
    r->data=3;

    node->right=r;

    int maxDiameter=diameter(node);
    cout<<maxDiameter<<endl;

    cout<<node->data<<" "<<node->left->data<<" "<<node->right->data<<endl;
}

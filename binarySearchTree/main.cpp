#include <iostream>
#include <string>
#include <queue>
#include <stack>

#define SPACE 10
using namespace std;

class TreeNode{
public:
    TreeNode *left;
    TreeNode *right;
    int value;

    TreeNode(){
    left=NULL;
    right=NULL;
    value=0;}

    TreeNode(int v){
        value=v;
        left=NULL;
        right=NULL;
    }
    };

class BST{
public:
    TreeNode* root;

    BST(){
    root=NULL;}

    bool isEmpty(){
        if(root==NULL){
            return true;
        }
        else
            return false;
    }
//
    void insertNode(TreeNode* newNode){
        if(root==NULL){
            root=newNode;
        }
        else{
            TreeNode* temp=root;
            while(temp!=NULL){
                if(newNode->value==temp->value){
                    cout<<"no duplicates allowed"<<endl;
                    return;
                }
                else if((newNode->value<temp->value) && (temp->left==NULL)){
                    temp->left=newNode;
                    break;
                }
                else if(newNode->value<temp->value){
                    temp=temp->left;
                }
                else if((newNode->value>temp->value) && (temp->right==NULL)){
                    temp->right=newNode;
                    break;
                }
                else{
                    temp=temp->right;
                }
            }
        }
        }

    TreeNode * minValueNode(TreeNode *node){
        TreeNode * curr=node;
        while(curr->left!= NULL){
            curr=curr->left;
        }
        return curr;
    }

    TreeNode * deleteNode(TreeNode * r,int v){
        if(r==NULL)
            return NULL;
        else if(v<r->value){
            r->left=deleteNode(r->left,v);
        }
        else if(v>r->value)
            r->right=deleteNode(r->right,v);

        else{
            if(r->left==NULL && r->right==NULL)
               {    delete r;
                    return NULL;
               }
            else if(r->left==NULL){
                TreeNode * temp=r->right;
                delete r;
                return temp;
            }
            else if(r->right==NULL){
                TreeNode *temp=r->left;
                delete r;
                return temp;
            }
            else{
                TreeNode* temp=minValueNode(r->right);
                r->value=temp->value;
                r->right=deleteNode(r->right,temp->value);
            }
        }
        return r;
    }
    void print2D(TreeNode *r,int space){
        if(r==NULL){
            return;
        }
        space+=SPACE; //increase distance between levels
        print2D(r->right,space);
        cout<<endl;
        for(int i=SPACE;i<space;i++){
            cout<<" ";
        }
        cout<<r->value<<"\n";
        print2D(r->left,space); //process left child
    }

    void printPreOrder(TreeNode *r){
        if (r==NULL){
            return ;
        }
        cout<<r->value<<endl;
        printPreOrder(r->left);
        printPreOrder(r->right);
    }

     void printInOrder(TreeNode *r){
        if (r==NULL){
            return ;
        }
        printInOrder(r->left);
        cout<<r->value<<endl;
        printInOrder(r->right);
    }

    void printInOrderIteratively(TreeNode *r){
        if(r==NULL)
            return ;
        stack<TreeNode*>stk;
        TreeNode *node=r;
        while(!stk.empty() || node!=NULL){
            if(node!=NULL){
                stk.push(node);
                node=node->left;
            }
            else{
                TreeNode * temp=stk.top();
                cout<<temp->value<<" ";
                stk.pop();
                node=temp->right;
            }
        }
        cout<<endl;
    }

    void printPreOrderIteratively(TreeNode *r){
        if(r==NULL)
            return ;
        stack<TreeNode*>stk;
        TreeNode *node=r;
        while(!stk.empty() || node!=NULL){
            if(node!=NULL){
                cout<<node->value<<" ";
                stk.push(node);
                node=node->left;
            }
            else{
                TreeNode * temp=stk.top();
                stk.pop();
                node=temp->right;
            }
        }
        cout<<endl;
    }

    void printPostOrderIteratively(TreeNode *r){
        if(r==NULL)
            return ;

        stack<TreeNode*>outp;
        stack<TreeNode*>stk;
        TreeNode *node=r;
        stk.push(node);
        while(!stk.empty()){
            TreeNode* temp=stk.top();
            stk.pop();
            outp.push(temp);

            if(temp->left!=NULL)
                stk.push(temp->left);
            if(temp->right!=NULL)
                stk.push(temp->right);
        }
        while(!outp.empty()){
            cout<<outp.top()->value<<" ";
            outp.pop();
        }
        cout<<endl;
    }


     void printPostOrder(TreeNode *r){
        if (r==NULL){
            return ;
        }
        printPostOrder(r->left);
        printPostOrder(r->right);
        cout<<r->value<<endl;
    }

    TreeNode* iterativeSearch(int val){
        if (root==NULL){
            return root;
        }
        else{
            TreeNode* temp=root;
            while(temp!=NULL){
                if (val==temp->value){
                    return temp;
                }
                else if(val<temp->value){
                    temp=temp->left;
                }
                else{
                    temp=temp->right;
                }
            }
        }
        return NULL;
    }

    int heightOfTree(TreeNode *r){
    if(r==NULL){
        return -1;
    }
    else{
        int lheight=heightOfTree(r->left);
        int rheight=heightOfTree(r->right);

        if(lheight>rheight)
            return lheight+1;
        else{
            return rheight+1;
        }
    }
    }

    void printLevelOrderQueue(TreeNode *r){
    if (r==NULL){
        cout<<"tree is empty"<<endl;
    }
    else{
    queue<TreeNode *> q;
    TreeNode *temp=r;
    q.push(temp);
    TreeNode *t;
    while(!q.empty()){
        t=q.front();
        q.pop();
        if(t==NULL){
            q.push(NULL);
            cout<<"\n";
        }
        else{
            cout<<t->value<<" ";
        if(t->left){
            q.push(t->left);
        }
        if(t->right){
            q.push(t->right);
        }
        }
        }
    }
    }
    void printGivenLevel(TreeNode* r,int level){
    if (r==NULL){
        return;
    }
    else if(level==0){
        cout<<r->value<<" ";
    }
    else{
        printGivenLevel(r->left,level-1);
        printGivenLevel(r->right,level-1);
    }
    }

    void rightView(TreeNode *root,int level,int *currLevel){
        if(root==NULL)
            return ;

        if(level>*currLevel){
            cout<<root->value<<" ";
            *currLevel=level;
        }
        rightView(root->right,level+1,currLevel);
        rightView(root->left,level+1,currLevel);

        return ;
    }


     void leftView(TreeNode *root,int level,int *currLevel){
        if(root==NULL)
            return ;

        if(level>*currLevel){
            cout<<root->value<<" ";
            *currLevel=level;
        }
        leftView(root->left,level+1,currLevel);
        leftView(root->right,level+1,currLevel);

        return ;
    }


    void printLevelOrderHeight(TreeNode *r){
        int h=heightOfTree(r);
        for(int i=0;i<=h;i++){
            printGivenLevel(r,i);
        }
    }
    };

int main()
{
    BST obj;
    int option;
    int val;
    int level=1;
    int currLevel=0;

    do{ cout<<"0. exit"<<endl;
        cout<<"1. Insert"<<endl;
        cout<<"2. iterativeSearch"<<endl;
        cout<<"3. heightOfTree"<<endl;
        cout<<"4. print"<<endl;
        cout<<"5. printPreOrder Recursively"<<endl;
        cout<<"6. printInOrder Recursively"<<endl;
        cout<<"7. printPostOrder Recursively"<<endl;
        cout<<"8. printLevelOrderTraversal using queue"<<endl;
        cout<<"9. printLevelOrderTraversal using Height"<<endl;
        cout<<"10. delete"<<endl;
        cout<<"11. printInOrder Iteratively"<<endl;
        cout<<"12. printPreOrder Iteratively"<<endl;
        cout<<"13. printPostOrder Iteratively"<<endl;
        cout<<"14. print leftView "<<endl;
        cout<<"15. print rightView "<<endl;

        cin>>option;


    TreeNode *newNode=new TreeNode();

    switch(option){
    case 0:
        break;
    case 1:
        cout<<"Insert"<<endl;
        cout<<"Enter Value of Tree TreeNode to insert in BST"<<endl;
        cin>>val;
        newNode->value=val;
        obj.insertNode(newNode);
        cout<<endl;
        break;
    case 2:
        cout<<"iterative search"<<endl;
        cout<<"Enter value of tree node to search"<<endl;
        cin>>val;
        cout<<obj.iterativeSearch(val)->value<<endl;
        break;
    case 3:
        cout<<"height of Tree"<<endl;
        cout<<obj.heightOfTree(obj.root)<<endl;
        break;
    case 4:
        cout<<"print"<<endl;
        obj.print2D(obj.root,5);
        break;
    case 5:
        cout<<"printPreOrder"<<endl;
        obj.printPreOrder(obj.root);
        break;
    case 6:
        cout<<"printInOrder"<<endl;
        obj.printInOrder(obj.root);
        break;
    case 7:
        cout<<"printPostOrder"<<endl;
        obj.printPostOrder(obj.root);
        break;
    case 8:
        cout<<"printLevelOrder"<<endl;
        obj.printLevelOrderQueue(obj.root);
        break;

    case 9:
        cout<<"printLevelOrder using height"<<endl;
        obj.printLevelOrderHeight(obj.root);
        break;
    case 10:
        cout<<"enter val to delete"<<endl;
        cin>>val;
        newNode=obj.iterativeSearch(val);
        if(newNode!=NULL){
            obj.deleteNode(obj.root,val);
            cout<<"Value Deleted"<<endl;
        }
        else{
            cout<<"value Not found"<<endl;
        }
        break;

    case 11:
        obj.printInOrderIteratively(obj.root);
        break;

    case 12:
        obj.printPreOrderIteratively(obj.root);
        break;
    case 13:
        obj.printPostOrderIteratively(obj.root);
        break;
    case 14:
        level=1;
        currLevel=0;
        obj.leftView(obj.root,level,&currLevel);
        break;
    case 15:
        level=1;
        currLevel=0;
        obj.rightView(obj.root,level,&currLevel);
        break;
    default:
        cout<<"enter proper option"<<endl;
        }
    }while(option!=0);
    return 0;
}

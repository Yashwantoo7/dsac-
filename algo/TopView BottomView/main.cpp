#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node * right;
    Node(){
        data=0;
        left=NULL;
        right=NULL;
    }
};

void topView(Node *root)
{
    queue<pair<int ,Node * >> q;
    map<int,vector<int>> Map;

    q.push(make_pair(0,root));
    map<int,vector<int>> ::iterator itr;
    while(!q.empty()){
        pair<int ,Node*> temp=q.front();
        q.pop();
        if(Map.find(temp.first)==Map.end()){
            Map[temp.first].push_back(temp.second->data);
        }
        if(temp.second->left!=NULL){
            q.push(make_pair(temp.first-1,temp.second->left));
        }

        if(temp.second->right!=NULL){
            q.push(make_pair(temp.first+1,temp.second->right));
        }

    }
    for(itr=Map.begin();itr!=Map.end();itr++){
       for(auto i:itr->second)
            cout<<i<<" ";
    }
}

vector <int> bottomView(Node *root)
{
   queue<pair<int ,Node * >> q;
    map<int,vector<int>> Map;

    q.push(make_pair(0,root));
    map<int,vector<int>> ::iterator itr;
    while(!q.empty()){
        pair<int ,Node*> temp=q.front();
        q.pop();
        Map[temp.first].push_back(temp.second->data);
        if(temp.second->left!=NULL){
            q.push(make_pair(temp.first-1,temp.second->left));
        }

        if(temp.second->right!=NULL){
            q.push(make_pair(temp.first+1,temp.second->right));
        }

    }

    vector<int> vec;

    for(itr=Map.begin();itr!=Map.end();itr++){
        vec.push_back(itr->second[itr->second.size()-1]);
    }
    return vec;
}

int main()
{
    queue<pair<int ,Node * >> q;
    Node *node=new Node;
    node->data=10;

    Node *root=node;

    node=new Node;
    node->data=5;
    root->left=node;

    node=new Node;
    node->data=15;
    root->right=node;

    cout<<root->data<<" "<<root->left->data<<" "<<root->right->data<<endl;
    topView(root);

    vector<int>bottom=bottomView(root);

    return 0;
}

#include <iostream>
#include <set>
#include<vector>
#include<map>
#include <iterator>

using namespace std;

class TreeNode{
public:

    int value;
    TreeNode * left;
    TreeNode * right;

    TreeNode(){
    value=0;
    left=NULL;
    right=NULL;
    }
};

class Solution{

    map<int,map<int,set<int>>> mymap;
    void solve(TreeNode *curr,int col,int row){
        if(!curr)
            return ;

        mymap[col][row].insert(curr->value);
        solve(curr->left,col-1,row+1);
        solve(curr->right,col+1,row+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode * root){
        solve(root,0,0);
        vector<vector<int>>ans;
        for(auto m1:mymap){
            ans.push_back(vector<int>());
            for(auto m2:m1.second){
                for(auto m3:m2.second)
                    ans.back().push_back(m3);
            }
        }
        return ans;
    }
};

int main()
{

    //map and vectors
    map<int,vector<int>> Map;
    map<int,vector<int>> ::iterator itr;
    int key,value;
    for(int i=0;i<6;i++){
        cin>>key;
        cin>>value;
        Map[key].push_back(value);

//        or

//        map<int,vector<int>> ::iterator itr=Map.find(key);
//        if(itr!=Map.end()){
////                Map[key].push_back(value);
//            cout<<"present"<<endl;
//            vector<int> &v=itr->second;
//            v.push_back(value);
////            Map[key].push_back(value);
//        }
//        else{
//            vector<int> &v=Map[key];
//            v.push_back(value);
////            Map[key].push_back(value);
//        }
    }

    for (itr=Map.begin();itr!=Map.end();itr++){
            cout<<itr->first<<" ->";
            for(auto i:itr->second){
                cout<<i<<",";
            }
    cout<<endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}

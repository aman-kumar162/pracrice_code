#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node():val(0),left(NULL),right(NULL){};
    Node(int x):val(x),left(NULL),right(NULL){};
    Node(int x,Node* left,Node* right): val(x),left(left),right(right) {}; 
};

vector<vector<int>> verticalTravesal(Node* root){
    map<int,map<int,multiset<int>>> node;
    queue<pair<Node,pair<int,int>>> q;
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    q.push({root,{0,0}});
    while (!q.empty())
    {
        auto p=q.front();
        q.pop();
        Node* var= p.first;
        int hd=p.second.first;
        int lvl=p.second.second;
        node[hd][lvl].insert(var->val);
        if(var->left){ q.push({var->left,{hd-1,lvl+1}});}
        if(var->right){ q.push({var->right,{hd+1,lvl+1}});}

    }
    for(auto i:node){
        vector<int> col;
        for(auto j:i.second){
            col.insert(col.end(),j.second.begin(),j.second.end());

        }
        ans.push_back(col);
    }
    return ans;
    


}

int main(){

}
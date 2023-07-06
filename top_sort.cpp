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

vector<int> Top_view(Node* root){
   vector<int> ans;
   if(root==NULL) return ans;
   map<int,int> mpp;
   queue<pair<Node*,int>> q;
   q.push({root,0});
   while (!q.empty())
   {
     auto it= q.front();
     q.pop();
     Node* node = it.first;
     int line= it.second;
  //important
     if(mpp.find(line) == mpp.end()){ mpp[line] = node->val;}
     if(node->left){ q.push({node->left,line-1});}
     if(node->right){ q.push({node->right,line+1});}
   }

   for(auto it: mpp)
{
    ans.push_back(it.second);
}   return ans;

}

int main(){

}
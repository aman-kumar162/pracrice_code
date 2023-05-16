#include<iostream>
using namespace std;
class Node{
 public:
  int val;
  Node* left;
  Node* right;
  Node(): val(0),left(NULL),right(NULL) {};
  Node(int x): val(x),left(NULL),right(NULL){};
  Node (int x,Node* right,Node* left): val(x),left(left),right(right){};
   
   Node* solve(Node* root,int &k,int node){
    if(root==NULL) return NULL;
    if(root->val== node) return root;

    Node* left=solve(root->left,k,node);
    Node* right=solve(root->right,k,node);

    if(left!=NULL && right==NULL){
        k--;
        if(k<=0) {
            k=INT8_MAX;
            return root;
        }
        return left;
    }

     if(left==NULL && right!=NULL){
        k--;
        if(k<=0) {
            k=INT8_MAX;
            return root;
        }
        return right;
    }
    return NULL;
   }

   int kthAncestor(Node* root,int k,int node){
    Node* ans=solve(root,k,node);
    if(ans==NULL ||  ans->val==node)
    return -1;
   }
   else
    return ans->val;



};

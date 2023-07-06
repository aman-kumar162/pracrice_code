#include<iostream>
using namespace std;
struct Node{
 
  int val;
  Node* left;
  Node* right;
  Node(): val(0),left(NULL),right(NULL) {};
  Node(int x): val(x),left(NULL),right(NULL){};
  Node (int x,Node* right,Node* left): val(x),left(left),right(right){};

};
Node* lca(Node* root,int n1,int n2){
    if(root==NULL) return NULL;
    if(root->val==n1 || root->val==n2) return root;

    Node* left= lca(root->left,n1,n2);
    Node* right=lca(root->right,n1,n2);

    if(left==NULL && right!=NULL)
    return right;

    if(left!=NULL && right==NULL)
    return left;

    if(left!=NULL && right!=NULL)
    return root;
    else return NULL;



}
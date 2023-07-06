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
void solve  (Node * root,int sum,int length,int &maxlen,int &maxsum){
    if(root==NULL){
        if(length>maxlen){
            maxlen=length;
            maxsum=sum;
        }
        else if( maxlen==maxsum){
            maxlen=max(maxlen,sum);
        }
        return ;
    }
    sum=sum+root->val;
    
     solve(root->left,sum,length+1,maxlen,maxsum);
     solve(root->right,sum,length+1,maxlen,maxsum);


}
int main(){
    int maxsum=INT8_MIN;
    int sum=0;
    int maxlength=0;
    int length=0;
     Node root();
    solve(root(),sum,maxlength,length,maxsum);
    return maxsum;

}
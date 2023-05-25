#include<bits/stdc++.h>
using namespace std;
int k(vector<int>&wt,vector<int>&val,int n,int W,vector<vector<int>> &dp){
    vector<int> prev(W,0);
   for(int i=wt[0];i<=W;i++){
    prev[i]=val[0];
   }
   for(int ind=1;ind<n;ind++){
     for(int cap=0;cap<=W;cap++){

    int nottaken= 0 + prev[cap];
    int taken=INT_MIN;
    if(wt[ind]<=cap)
       taken=val[ind]+prev[cap-wt[ind]];
     prev[cap]=max(nottaken,taken);}}
    return prev[W];
}
int main(){
  vector<int> wt={1,2,4,5};
  vector<int> val={5,4,8,6};
  int W=5;
  int n=wt.size();
   vector<vector<int>> dp(n,vector<int>(W+1,0));
    cout<<k(wt,val,n,W,dp);
}
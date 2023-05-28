#include<bits/stdc++.h>
using namespace std;
int unbounded(int n,vector<int> &wt,vector<int>&val,int W,vector<vector<int>> &dp){
   if(n==0){
      return ((int)(W/wt[0]))*val[0];
   }
   if(dp[n][W]!=-1) return dp[n][W];

      int notpick=0+unbounded(n-1,wt,val,W,dp);
      int pick=INT_MIN;
      if(wt[n]<=W) 
       pick=val[n] + unbounded(n,wt,val,W-val[n],dp);

     return    dp[n][W]=max(pick,notpick);
}

int main(){
 vector<int> wt={2,4,6};
 vector<int> val={5,11,13};
   int W=10,n=3;
   vector<vector<int>> dp (n,vector<int>(W+1,-1));
 cout<<unbounded(n-1,wt,val,W,dp);

}
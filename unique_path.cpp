#include<bits/stdc++.h>
using namespace std;

int path(int m,int n,vector<vector<int>>&dp){
if(m==0 && n==0) return 1;
if(m<0 || n<0) return 0;
if(dp[m][n]!=-1) return dp[m][n];
 
 int left=path(m-1,n,dp);
 int right=path(m,n-1,dp);
 return  dp[m][n]=left+right;
}
int main(){
   int m=3,n=3;
   cout<<"starting";
 vector<vector<int>> dp(m,vector<int>(n,-1));
      cout<< path(m-1,n-1,dp);
    
   cout<<"sucess !";
}
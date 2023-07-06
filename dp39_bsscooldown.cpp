#include<bits/stdc++.h>
using namespace std;
int sol(vector<int> arr,int ind,int buy,int n,vector<vector<int>> &dp){
    if(ind>=n) return 0;
      int op1,op2;
      if(dp[ind][buy]!=-1) return dp[ind][buy];
      
    if(buy==0){
           op1=0+sol(arr,ind+1,0,n,dp);
           op2=-arr[ind]+sol(arr,ind+1,1,n,dp);
    } 
    if(buy==1){
        op1=0+sol(arr,ind+1,1,n,dp);
        op2=arr[ind]+sol(arr,ind+2,0,n,dp);
    }
    return dp[ind][buy]=max(op1,op2);

   
}

//tabulation
int cal2(vector<int>arr,int n){
    vector<vector<int>>dp(n+2,vector<int>(2,0));
   
     for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
             int op1,op2;
             if(buy==0){
           op1=0+dp[ind+1][0];
           op2=-arr[ind]+dp[ind+1][1];
    } 
    if(buy==1){
        op1=0+dp[ind+1][1];
        op2=arr[ind]+dp[ind+2][0];
    }
    dp[ind][buy]=max(op1,op2);
        }
     }
     return dp[0][0];
}
//tabulation+ space opt optimisation
int cal2(vector<int>arr,int n){
       vector<int> cur(2,0);
       vector<int> front1(2,0);
       vector<int> front2(2,0);

   
     for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
             int op1,op2;
             if(buy==0){
           op1=0+front1[0];
           op2=-arr[ind]+front1[1];
    } 
    if(buy==1){
        op1=0+front1[1];
        op2=arr[ind]+front2[0];
    }
    cur[buy]=max(op1,op2);
        }
        front2=front1;
        front1=cur;
     }
     return cur[0];
}

/*recursion  +memorisation*/
int cal1(vector<int> arr,int n){
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return (sol(arr,0,0,n,dp));
}
int main(){
    vector<int> arr={4,9,0,4,10};
    cout<< cal2(arr,arr.size());
}
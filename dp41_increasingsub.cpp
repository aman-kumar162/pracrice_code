#include<bits/stdc++.h>
using namespace std;
int getans(int arr[],int n,int ind,int prev_ind,vector<vector<int>> &dp){
    if(ind==n) return 0;
    if(dp[ind][prev_ind+1]!=-1){
        return dp[ind][prev_ind+1];
    }
    int nottake=0+getans(arr,n,ind+1,prev_ind,dp);
    int take=0;
    if(prev_ind==-1 || arr[ind]>arr[prev_ind])
       take=1+getans(arr,n,ind+1,ind,dp);
    return dp[ind][prev_ind+1]=max(nottake,take);   
}
int lis(int arr[],int n){
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return getans(arr,n,0,-1,dp);
}
int main(){
    int arr[]={10,9,2,5,3,7,101,18};
     int n=sizeof(arr)/sizeof(arr[0]);
     cout<<lis(arr,n);
     return 0;
}
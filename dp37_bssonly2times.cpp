#include<bits/stdc++.h>
using namespace std;
/*
int profit1(long arr[],int n){
    vector<vector<vector<long>>> dp (n+1,vector<vector<long>>(2,vector<long>(3,0)));

    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                if(buy==0){
                 dp[i][buy][cap]=max((0+dp[i+1][0][cap]),-arr[i]+dp[i+1][1][cap]);}
                if(buy==1){
                 dp[i][buy][cap]=max((0+dp[i+1][1][cap]),arr[i]+dp[i+1][0][cap-1]);
                
            }
        }
    }
    return dp[0][0][2];
}    //trun 0 ,1,2,3*/ 
int profit1(long arr[],int n){
     vector<vector<long>> dp(n+1,vector<long>(4,0));
   
    for(int i=n-1;i>=0;i--){
        for(int tran=0;tran<=3;tran++){
       if(tran%2==0){
                 dp[i][tran]=max((0+dp[i+1][tran]),-arr[i]+dp[i+1][tran+1]);}
        else{
                 dp[i][tran]=max((0+dp[i+1][tran]),arr[i]+dp[i+1][tran+1]);
                }
            }}
    return dp[0][3];
}
int main(){
int n=6;
long arr[n]={3,3,5,0,0,3,1,4};
   cout<<"the ans"<<profit1(arr,n);


}
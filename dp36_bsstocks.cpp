#include<bits/stdc++.h>
using namespace std;
int profit(long *arr,int n){
    vector<vector<long>> dp(n,vector<long>(2,-1));
    dp[n][0]=dp[n][1]=0;
    long profit;
    for(int i=n-1;i>=0;i--){
        for(int by=0;by<=1;by++){
            //0 representing i can buy the estocks 
            if(by==0){
                profit=max(0+dp[i+1][0],-arr[i]+dp[i+1][1]);
            }
            // 1 represent i can sell the stocks only 
            if(by==1){
                profit=max(0+dp[i+1][1],arr[i]+dp[i+1][0]);
            }
            dp[i][by]=profit;
        }
    }
    return dp[0][0];
}
int profit1(long arr[],int n){
    vector<vector<long>> dp(n+1,vector<long>(2,-1));
      vector<long> ahead(2,0);
      vector<long>  cur(2,0);
     ahead[0]=ahead[1]=0;
  long profit;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=1;j++){
               if(j==0){
                profit=max(0+ahead[0],-arr[i]+ahead[1]);
               }else  
                 profit=max(0+ahead[1],arr[i]+ahead[0]);
                 cur[j]=profit;


        }
        ahead=cur;
    }
    return cur[0];
}
int main(){
int n=6;
long arr[n]={7,1,5,3,6,4};
   cout<<"the ans"<<profit1(arr,n);


}
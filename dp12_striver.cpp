#include<bits/stdc++.h>
using namespace std;
int maxi(vector<vector<int>> matrix){

    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int j=0;j<m;j++){
        dp[0][j]=matrix[0][j];
    }
    for (int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up=matrix[i][j]+dp[i-1][j];
            int lu=matrix[i][j];
            if(j-1>=0)// standing se ek piche
             lu +=dp[i-1][j-1];
            else lu+=-1e9;

             int ru=matrix[i][j];
             if(j+1<m)// staanding se ek age
              ru+=dp[i-1][j+1];
             else
              ru+=-1e9;

              dp[i][j]=max(up,max(ru,lu)); 
        }
    }
    int maxi=INT_MIN;
    for(int j=0;j<m;j++){
        maxi=max(maxi,dp[n-1][j]);
    }
    return maxi;
}

int maxii(vector<vector<int>>matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int > prev(n,0),curr(n,0);
    //initalising the first  row index
    for(int j=0;j<m;j++){
        prev[j]=matrix[0][j];

    }
    // here we start from i=1 becs we already stored the value of  for i=0 
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up=matrix[i][j]+prev[j];
            int leftdiag=matrix[i][j];
            if(j-1>=0) leftdiag+=prev[j-1];
            else  leftdiag+=-1e9;
            int rightdiag=matrix[i][j];
            if(j+1<m) 
            rightdiag+=prev[j+1];
            curr[j]=max(up,max(leftdiag,rightdiag));
        }
        prev=curr;
    }
    int maxi=INT_MIN;
    for(int j=0;j<n;j++){
        maxi=max(maxi,prev[j]);
    }
    return maxi;
}

int  main(){
  
  vector<vector<int>> mat{{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
  cout<<"the value is "<<maxi(mat);
}
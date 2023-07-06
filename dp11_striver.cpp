#include<bits/stdc++.h>
using namespace std;
class memoriasiton{
public:    
  int minval(int r,int c,vector<vector<int>>trial,int n,vector<vector<int>> &dp){
   if(dp[r][c]!=-1)  return dp[r][c];
   if(r==n-1) return trial[r][c];

int down=trial[r][c]+minval(r+1,c,trial,n,dp);
int diagonal=trial[r][c]+minval(r+1,c+1,trial,n,dp);

 return    dp[r][c]=min(down,diagonal);

  }
int minpath(vector<vector<int>> trial,int n){
 
     vector<vector<int>> dp(n,vector<int>(n,-1));
      return   minval(0,0,trial,n,dp);   
   
}

};
class tabulation{
 public:   
    int minpath(vector<vector<int>> trial ,int n){
      vector<int>dp(n,0);
      vector<int> front;
      for(int i=0;i<n;i++){
          dp[i]=trial[n-1][i];

      }
      for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down=trial[i][j]+dp[i];
            int diag=trial[i][j]+dp[i+1];
            front[i]=min(down,diag);

        }
           dp=front;
           
      }
    
        return dp[0];
    }
};
int main(){
   vector<vector<int>> triangle{{1},{2,3},{3,6,7},{8,9,6,10}};
   int n=triangle.size();
      tabulation obj;
    cout<<"the min path sum is"<<obj.minpath(triangle,n);
}
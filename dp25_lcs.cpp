#include<bits/stdc++.h>
using namespace std;
int fin(int i1,int i2,string s1,string s2){
if(i1<0 || i2<0){
    return 0;
}
  if(s1[i1]==s2[i2]) return 1+fin(i1-1,i2-1,s1,s2);
  return 0+max(fin(i1,i2-1,s1,s2),fin(i1-1,i2,s1,s2));
}
 int dpf(int i1,int i2,string &s1,string &s2,vector<vector<int>> &dp){
    if(i1<0 || i2<0){
    return 0;
}  
   if(dp[i1][i2]!=-1) return dp[i1][i2];

  if(s1[i1]==s2[i2]) return dp[i1][i2]=1+fin(i1-1,i2-1,s1,s2);
  return dp[i1][i2]=0+max(fin(i1,i2-1,s1,s2),fin(i1-1,i2,s1,s2));
}  
int lcs(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
     return dpf(n-1,m-1,s1,s2,dp);
   }
int lcs1(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
     for(int i=0;i<=n;i++) dp[0][i]=0;
     for(int i=0;i<=m;i++) dp[i][0]=0;

     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])  dp[i][j]=1+dp[i-1][j-1];
            else 
                dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
        }
     }
         return dp[n][m];
   }

int main(){
   string s1="acd";
   string s2="ced";
   cout<<"the length is "<<lcs1(s1,s2);

}
#include<bits/stdc++.h>
using namespace std;
string lcs(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=0+max(dp[i-1[j],dp[i][j-1]);
            }
        }
      }
         int len=dp[n][m];
      int i=n;
      int j=m;
     string ans="";
     int index=len-1;
     while(i>0||j>0){
            if(s1[i-1]==s2[j-1]){
                   ans+=s1[i-1];
                   i--,j--;
                   index--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                  ans+=s1[i-1];
                   i--; 
            }
            else{  ans+=s2[j-1];
                       j--;
              }
     }
     reverse(ans.begin(),ans.end());
   return ans;
}

int main(){
  string s1="brute";
  string s2="groot";
   cout<<"the string is" <<lcs(s1,s2); 
}
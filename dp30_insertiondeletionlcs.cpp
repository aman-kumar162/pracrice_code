#include<bits/stdc++.h>
using namespace std;


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
/*
int main(){
   string s1="acda";
   string s2="ced";

      int n=s1.size();
      int m=s2.size();
      int total=m+n-2*lcs1(s1,s2);
   cout<<"the length is "<<total;

}*/

int main(){
   string s1="abca";
     string s2=s1;
  reverse(s1.begin(),s1.end());
   int insertion=s1.size()-lcs1(s1,s2);

   
   cout<<"the length is "<<insertion;
}
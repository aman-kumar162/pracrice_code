#include<bits/stdc++.h>
using namespace std;
int lcsu(string s1,string s2,int i,int j,vector<vector<int>>&dp){
    if(i<0 ||j<0 ) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]) return dp[i][j]=1+lcsu(s1,s2,i-1,j-1,dp);
    else
      return dp[i][j]=0+max(lcsu(s1,s2,i,j-1,dp),lcsu(s1,s2,i-1,j,dp));
}
int lcs(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> vis(n,vector<int>(m,-1));

    return  lcsu(s1,s2,n-1,m-1,vis);
}
int main(){
   string s1="abcead";
   string s2="cead";

   cout<<lcs(s1,s2);

}
#include<bits/stdc++.h>
using namespace std;
bool isAllStars(string & S1, int i) {
  for (int j = 0; j <= i; j++) {
    if (S1[j] != '*')
      return false;
  }
  return true;
}
bool match(string &s1,string &s2,int i,int j,vector<vector<bool>>&dp){
 if(i<0 && j<0) return 1;
 if(i<0 && j>=0) return 0;
  if (j < 0 && i >= 0)
    return isAllStars(s1, i);

if(s1[i]==s2[j]||s1[i]=='?') return match(s1,s2,i-1,j-1,dp);
else{
   if(s1[i]=='*') return match(s1,s2,i-1,j,dp)||match(s1,s2,i,j-1,dp);
   else return false;
}

}
bool wildcard(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<bool>> dp(n,vector<bool>(m,-1));
    return match(s1,s2,n-1,m-1,dp);
}
int main(){
  string s1="ab*cd";
  string s2="abdefcd";
  if(wildcard(s1,s2)){
    cout<<"string match";
  }else 
    cout<<"do not match";
}
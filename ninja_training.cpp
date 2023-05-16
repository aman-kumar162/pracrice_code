#include<iostream>
#include<vector>
using namespace std;
int f(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp){
   if(dp[day][last]!=-1) return dp[day][last];
   if(day==0){
    int maxi=0;
    for(int i=0;i<=2;i++){
        if(i!=last){
            maxi=max(maxi,points[0][i]);

        }

    }
    return dp[day][last]=maxi;
   }
   int maxi=0;
   for(int i=0;i<=2;i++){
    if(i!=last){
     int activity = points[day][i]+f(day-1,i,points,dp);
      maxi = max(maxi, activity);}
   }
  return dp[day][last]=maxi;
}

int main(){
    vector<vector<int>>point= {{5,10,8},{7,10,45},{4,23,45},{45,78,2}};
    
    int days=point.size();
     vector<vector<int>> dp(days,vector<int>(4,-1));
   
    cout<<"the maximum point can earn by while traing"<<f(days-1,3,point,dp);

}
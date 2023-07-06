#include<bits/stdc++.h>
using namespace std;
 /* bool fun(int ind,int target,vector<int> arr, vector<vector<bool>> & dp){
    if(target==0) return true;
    if(ind==0) {if(arr[0]==target) return true; else false;}
    if(dp[ind][target]!=-1)return dp[ind][target];
  
     bool nottaken= fun(ind-1,target,arr,dp);
     bool taken=false;
       if(arr[ind]<=target)  
           taken=fun(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target]=nottaken||taken;       

  }
bool canpartition(int n,vector<int>arr){
   int size=0;
   for(int i=0;i<n;i++){
       size+=arr[i];
   }
   if(size/2==1) return false;
   else{
     int  k=size%2;
    vector<vector<bool>> dp(n,vector<bool>(k,-1));
       return fun(n-1,k,arr,dp);
   }
}
*/
bool can(int n ,vector<int> arr){
    int tsum=0;
    for(int i=0;i<n;i++){
        tsum+=arr[i];
    }
    if(tsum%2==1) return false;
    else{
        int k=tsum/2;
        vector<bool> prev(k+1,false);
        prev[0]=true;

        if(arr[0]<=k)
           prev[arr[0]]=true;
        for(int ind=1;ind<n;ind++){
            vector<bool> cur(k+1,false);
            cur[0]=true;

            for(int target=1;target<=k;target){
                bool nottaken=prev[target];
                bool taken = false;
                    if(arr[ind]<=target)
                        taken = prev[target-arr[ind]];
            cur[target]= nottaken||taken;
            }
            prev=cur;
        } 
           return prev[k];
    }
   
}

int main(){
vector<int> arr={9,3,3,4,5};
int n=arr.size();
if(can(n,arr)){
    cout<<"can be partition into two parts";

}
else
   cout<<"cannnot partition in to tw eql subset";
return 0;
}
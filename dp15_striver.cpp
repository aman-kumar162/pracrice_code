#include<bits/stdc++.h>
using namespace std;
bool subsetutil(int ind,int target,vector<int> arr,vector<vector<int>> dp){
    if(target==0) return true;
    if(ind==0) return arr[0]==target;
    if(dp[ind][target]!=-1) return dp[ind][target];

    bool nottaken=subsetutil(ind-1,target,arr,dp);
    bool taken=false;
    if(arr[ind]<=target) taken=subsetutil(ind-1,target-arr[ind],arr,dp);

    return dp[ind][target]=nottaken||taken; 
}
bool subseta(int n,int target,vector<int> arr){
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return subsetutil(n-1,target,arr,dp);
}
bool subset(int n,int k,vector<int> &arr){
   vector<bool> prev(k+1,false);
   prev[0]=true;
   if(arr[0]<=k
   ){
    prev[arr[0]]=true;
   }
   for(int ind=1;ind<n;ind++){
    vector<bool> cur(k+1,false);
         cur[0] = true;
        for(int target= 1; target<=k; target++){
            bool notTaken = prev[target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = prev[target-arr[ind]];
        
            cur[target]= notTaken||taken;
        }
        prev=cur;
   }
   return prev[k];
}
int main(){
vector<int> arr={1,2,3,4};
int k=7;
int n=arr.size();
if(subset(n,k,arr)){
    cout<<"found";

} 
else  
  cout<<"not found";
}
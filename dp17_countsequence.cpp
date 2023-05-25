#include<bits/stdc++.h>
using namespace std;

int possible(vector<int> arr,int target){
   
    int n=arr.size();
    vector<int> dp(target+1,0);
   
      dp[0]=1;
    
    if(arr[0]<=target)  dp[arr[0]]=1;
 vector<int> curr(target+1,0);
    for(int ind=1;ind<n;ind++){
        curr[0]=1;
        for(int tar=1;tar<=target;tar++){
             int nottaken= dp[tar];
             int taken=0;
             if(arr[ind]<=tar) taken=dp[tar-arr[ind]];
             curr[tar]=nottaken+taken;
        }
        dp=curr;
    }

    return  dp[target];

}
int main(){
    vector<int> arr={1,2,2,3};
      int target=3;
 cout<<"possibl target sum is"<<      possible(arr,target);

      return 0;

}
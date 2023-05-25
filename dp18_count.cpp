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
int countpart(vector<int> arr,int d){
    int tar=0;
    for(int i=0;i<arr.size();i++){
        tar+=arr[i];
    }
      int s2= (tar-d)/2;
      return possible(arr,s2);
}
int main(){
    vector<int> arr={6,6,2,4};
    int d=2;
    cout<<"possibility is "<< countpart(arr,d);

}
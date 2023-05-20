#include<bits/stdc++.h>
using namespace std;
int minsub(vector<int> &arr,int n){
    int totsum=0;
    for(int i=0;i<n;i++){
        totsum+=arr[i];

    }  
            /*      dp[0][0]
                      [1][1]
                      [2][2]
                      [3][3]
                      [n][target]
*/
    vector<vector<bool>> dp(n,vector<bool>(totsum+1,false));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    if(arr[0]<=totsum) dp[0][totsum]=true;

    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=totsum;target++){
            bool notTaken=dp[ind-1][target];
            bool taken=false;
            if(arr[ind]<=target)
                  taken=dp[ind-1][target-arr[ind]];
              dp[ind][target]=notTaken||taken;    
        }
    }
    int mini=1e9;
    for(int i=0;i<=totsum;i++){
        if(dp[n-1][i]==true){
                   //subset-a  subset-b
            int diff=abs(i-(totsum-i));
            mini=min(mini,diff);
        }
    }
    return mini;
}
int minsub1(vector<int>&arr,int n){
    int totsum=0;
    for(int i=0;i<n;i++){
        totsum+=arr[i];
    }
    //1-D vector prev [0,1,2,3, _ _ _ _ totsum]

    vector<bool> prev(totsum+1,false);
    prev[0]=true;// bcs 0 always possible 
    if(arr[0]<=totsum)  prev[arr[0]]=true;// 
    for(int ind=1;ind<n;ind++){
        vector<bool> cur(totsum+1,false);
        cur[0]=true;
        for(int target=1;target<=totsum;target++){
            bool nottaken=prev[target];
            bool taken=false;
            if(arr[ind]<=target)
                  taken=prev[target-arr[ind]];
             cur[target]=nottaken||taken;      
        }
        prev=cur;
    }
    int mini=1e9;
    for(int i=0;i<=totsum;i++){
        if(prev[i]==true){
            int diff=abs(i-(totsum-i));
            mini=min(mini,diff);
        }
    }
    return mini;

}
int main(){
   vector<int> arr={1,3,3,4};
   int n=arr.size();
   cout<<"the minimum absolute difference is "<<minsub(arr,n);
   return 0;
}
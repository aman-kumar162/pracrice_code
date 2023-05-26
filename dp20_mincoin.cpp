#include<bits/stdc++.h>
using namespace std;
int minans(vector<int>arr,int t){
    int n=arr.size();
   //vector<vector<int>> dp(n,vector<int>(t+1,0));
   vector<int> prev(t+1,0) ,curr(t+1,0);
    for(int i=0;i<=t;i++){if(i%arr[0]==0)
        
        prev[i]=i/arr[0];
        else prev[i]=1e9;
    }

    for(int i=1;i<n;i++){
        for(int tar=0;tar<=t;tar++){
           int nottake=0+prev[tar];
           int take=1e9;
           if(arr[i]<=tar)
             take=1+curr[tar-arr[i]];
             curr[tar]=min(nottake,take);
        }
        prev=curr;
    }
    int ans=prev[t];
    if(ans>=1e9) return -1;
    return ans;
}
int main(){
    vector<int> arr={1,2,3};
    int tar=7;
    cout<<minans(arr,tar);

}
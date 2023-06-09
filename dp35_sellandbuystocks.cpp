#include<bits/stdc++.h>
using namespace std;
int profit(int arr[],int n){
    int maxprofit=0;
    int mini=arr[0];
    for(int i=1.;i<n;i++){
        int currProfit=arr[i]-mini;
        maxprofit=max(maxprofit,currProfit);
        mini=min(mini,arr[i]);
    }
}
int main(){
    int arr[]={7,1,5,6,3};
    cout<<profit(arr,5);
}
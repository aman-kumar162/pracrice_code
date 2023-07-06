#include<bits/stdc++.h>
using namespace std;
int binser(int  arr[],int n){
    vector<int> temp;
    int count;

    temp.push_back(arr[0]);
    count=1;
    for(int i=1;i<n;i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
            count++;
        }
        else{
            int res=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[res]=arr[i];
        }
    }
    return count;

}
int main(){
    int arr[]={10,9,2,5,3,7,101,18};
  int size=sizeof(arr)/sizeof(arr[0]);
    cout<<binser(arr,size);
}
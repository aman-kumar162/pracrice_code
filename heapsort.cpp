#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>&arr,int n,int index){
    int right=2*index+2;
    int left=2*index+1;
    int min=index;
    if(left<n && arr[left]<arr[min]){
        min=left;

    }
    if(right<n && arr[right]<arr[min]){
        min=right;
    }
    if(min!=index){
        swap(arr[index],arr[min]);
        heapify(arr,n,min);
    }

}
void heapsort(vector<int> &arr,int n){
  for(int i=(n/2)-1;i>=0;i--){
    heapify(arr,n,i);
  }
  for(int i=n-1;i>0;i--){
    swap(arr[0],arr[i]);
    heapify(arr,i,0);
  }
}
void printheap(vector<int>&arr,int n){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";

    }
    cout<<"\n";
}

int main(){
    vector<int> arr={1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
   int n=arr.size();
   heapsort(arr,n);
   cout<<"sorted arry";
   printheap(arr,n);
return  0;

}
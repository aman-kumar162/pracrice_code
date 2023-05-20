#include<iostream>
using namespace std;
int  mcm(int start,int end,int arr[]){
  if(start== end) return 0;
  int k;
  int mini=INT8_MAX;
  int count;
  for(k=start;k<end;k++){
    count=mcm(start,k,arr)+mcm(k+1,end,arr)+arr[start-1]*arr[k]*arr[end];
    
    mini=min(count,mini);

  }
   return mini;

}
int main(){
   int arr[]={1,2,3,4,3};
   int n=5;
   cout<<"the cost of multiplication is "<<
   mcm(1,n-1 ,arr);
   return 0;
}
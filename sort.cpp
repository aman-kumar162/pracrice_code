#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int a[100];


int partition(int arr[],int l,int r){
   int temp;
   int pivot=a[l];
   int i=l+1;
   int j=r;
   do{
    while(a[i]  <= pivot)i++;
    while(a[j]>pivot)j--;
    if(i<j) {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;

    }

   }while(i<j);
   temp=a[l];
   a[l]=a[j];
   a[j]=temp;

   return i;

}
void quicksort(int arr[],int low,int high){
    int top;
    if(low<high){
        top=partition(arr,low,high);
        quicksort(arr,low,top-1);
        quicksort(arr,top+1,high);
    }
}
int main(){
    int a[8]={2,8,7,1,3,5,6,4};
    int n=8;
    
	quicksort(a,0,n-1);
	cout<<"sorted array elements are:\n";
	for(int i=0;i<n;i++)
	cout<<a[i]<<"  ";
    return 0;

}
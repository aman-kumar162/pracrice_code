#include<iostream>
using namespace std;
void travelingprob(int size,int s[],int f[]){
     int i,j;
     cout<<"the following activity selected are  at particular index";
     i=0;
     cout<<i;
     for (j=1;j<size;j++){
            if(s[j]>=f[i]){
                cout<<j ;
                i=j;
            }

     }
}
int main()
    {

       int s[]={1,3,0,5,8,5};
       int f[]={2,4,6,7,9,9};
       int size= 6;
       travelingprob(size,s,f);
       return 0;


    }

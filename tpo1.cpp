#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i=1;i<=100;i++){
        if(i%3==0 && i%5==0) cout<<"CodeQuotient"<<endl;
        else if(i%3==0) cout<<"code"<<endl;
        else if(i%5==0) cout<<"Quotient"<<endl;
        else{ cout<<i<<endl; }

    }
    return 0;
}
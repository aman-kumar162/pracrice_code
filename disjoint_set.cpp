#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank,parent,size;

public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    // path compression
    int findUPar(int node){
         if(node==parent[node]) return node;
   return parent[node]=findUPar(parent[node]);
    } 

    void unionByRank(int u,int v){
        int ulp_v=findUPar(v);
        int ulp_u=findUPar(u);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            //means ulp_u wale ke parent ko v wale se update kr diya 
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            //means ulp_v wale ke parent ko u wale se update kr diya 
            parent[ulp_v]=ulp_u;
        }
        else{ //means ulp_u wale ke parent ko    v     wale se update kr diya 
            parent[ulp_u]=ulp_v;
            //jo v wala hai uske rank ko increase kr 
            rank[ulp_v]++;
        }
    }
            void unionBysize(int u,int v){
                int ulp_u=findUPar(u);
                int ulp_v=findUPar(v);
                if(ulp_u == ulp_v) return ;
                if(size[ulp_u]<size[ulp_v]){
                    parent[ulp_u]=ulp_v;
                    size[ulp_v]+=size[ulp_u];
                }
                else{
                    parent[ulp_v]=ulp_u;
                    size[ulp_u]+=size[ulp_v];
                }
            }

};

int main(){
   DisjointSet ds(7);
   ds.unionBysize(1,2);
   ds.unionBysize(2,3);
   ds.unionBysize(4,5);
   ds.unionBysize(6,7);
   ds.unionBysize(5,6);
   if(ds.findUPar(3)==ds.findUPar(7)){
    cout<<"same\n";
    
   }
   else   cout<<"not same \n";
   ds.unionBysize(3,7);
       if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;

}
#include<bits/stdc++.h>
using namespace std;
class Solution{
 public:

 vector<int> dijkstra(vector<vector<int>>adj[],int v,int sr){  
           //dist,src
    set <pair<int,int>> st;
    vector<int> dis(v,1e9);
    st.insert({0,sr});
    dis[sr]=0;
    while (!st.empty())
    {   auto it=*(st.begin());// to get the min dis node from set
              int  dist=it.first;
              int  node=it.second;
              st.erase(it);
              for(auto it: adj[node]){
                int adjnode=it[0];
                int edgew=it[1];
                if(dist+edgew< dis[adjnode]){
                    if(dis[adjnode]!=1e9){
                        st.erase({dis[adjnode],adjnode});

                        dis[adjnode]=edgew+dist;
                        st.insert({dis[adjnode],adjnode});
                    }
                }
              }

    }
    

   return dis;
 }

};
int main(){
    int v=3,e=3,s=2;
    vector<vector<int>> adj[v];
    vector<vector<int >> edges;
    edges={{0,1,1},{0,2,6},{1,2,3},{1,0,1},{2,1,3},{2,0,6}};
    for(auto it: edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        adj[u].push_back({v,wt});
    }
    Solution obj;
    vector<int> ans=obj.dijkstra(adj,v,s);

    for(int i=0;i<v;i++){
    cout<<ans[i]<<" ";}
    cout<<endl;
    return 0;
}
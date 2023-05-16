#include<bits/stdc++.h>
using namespace std;

class solution{
    private:
    void dfs(int i,vector <pair<int,int>> adj[],int vis[],stack<int>&st){
       vis[i]=1;
       for(auto it:adj[i]){
        int v=it.first;
        if(!vis[v])
          dfs(v,adj,vis,st);
       }
       st.push(i);
    }

public:
   vector<int> shortest(int n,int m,vector<vector<int>> edge){
      vector<pair<int,int>>   adj[n];
      for(int i=0;i<m;i++){
        int u=edge[i][0];
        int v=edge[i][1];
        int wt=edge[i][2];
        adj[u].push_back({v,wt});
      }
      int vis[n]={0};
      stack<int> st;
      for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
      }

      vector<int>dis(n);
      for(int i=0;i<n;i++){
        dis[i] = 1e9;
      }
      dis[0]=0;
      while(!st.empty()){
        int node=st.top();
        st.pop();

        for(auto it:adj[node]){
            int v=it.first;
            int wt=it.second;  
            if(dis[node]+wt <dis[v]){
          dis[v]=wt+dis[node];

            }      }
      }
        for (int i = 0; i < n; i++) {
        if (dis[i] == 1e9) dis[i] = -1;
      }
      return dis;
    }





   

};
int main(){
 int m=6, n=7;
 solution obj;
    vector<vector<int>> mp={{0,1,2},{0,4,1},{4,5,4},{4,2,0},{1,2,0},{2,3,0},{5,3,0}};
vector<int> ans= obj.shortest(m,n,mp);

for(auto i:ans){
    cout<<i<<" ";
}
return 0;
}
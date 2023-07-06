#include<bits/stdc++.h>
using namespace std;
class solution{
    void dfs(int v,vector<int> & vis,stack<int> &st,vector<int> adj[])
    {
        vis[v]=1;
          for(auto it:adj[v]){
            if(!vis[it])
             dfs(it,vis,st,adj);
          }
          st.push(v);
    }
public:
   vector<int> topo(int v,vector<int> adj[]){
   stack<int> st;
   vector<int> vis(v,0);

    for(int i=0;i<v;i++){
        if(vis[i]==0){
            dfs(i,vis,st,adj);
        }
    }
    vector<int> s;
    while (!st.empty())
    {
        s.push_back(st.top());
        st.pop();
    }
    
    return s;
   }


};

int main(){
   int n=6;
   vector<int> adj[6];
   adj[5].push_back(2);
   adj[5].push_back(0);
   adj[4].push_back(0);
   adj[4].push_back(1);
   adj[2].push_back(3);
   adj[3].push_back(1);

   solution obj;
   vector<int> res=obj.topo(6,adj);

   cout<<"toposort of given graph is :"<<endl;
   for(int i=0;i<res.size();i++)
   cout<< res[i]<<" ";
return 0;
   
}
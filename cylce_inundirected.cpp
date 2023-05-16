#include<bits/stdc++.h>
using namespace std;
class solution{
private:
bool cycledfs(int sc ,int parents,vector<int> adj[],int vis[]){
  vis[sc]=1;
  for(auto call: adj[sc]){
    if(!vis[call]){
        if(cycledfs(call,sc,adj,vis)==true) return true;
    }
    else if( call!=parents)return true;
  }
  return false;
}
   bool cycle(int src,vector<int> adj[],int vis[]){
     vis[src]=1;
     queue<pair<int,int>> q;
     q.push({src,-1});
       while (!q.empty())
       {
        int node=q.front().first;
        int parent=q.front().second;
          q.pop();

          for(auto ad:adj[node]){
            if(!vis[ad])
            {
                vis[ad]=1;
                q.push({ad,node});
            }
            else if(parent!=ad){
                return true;

            }
           
          }
       }
     return false; 
   } 
public:
   bool iscycle(int v,vector<int>adj[]){
    int vis[v]={0};
    for(int i=0;i<v;i++){
       if(!vis[i]){
         if(cycledfs(i,-1,adj,vis)==true) return true;
   }    }
   return false;
   }
};
int main(){
 vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    solution obj;
    bool ans = obj.iscycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}
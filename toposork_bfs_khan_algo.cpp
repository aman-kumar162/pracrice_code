#include<bits/stdc++.h>
using namespace std;
class solution{
public:
 bool check(int v, vector<int> adj[]){
     int indegree[v]={0};
    for(int i=0;i<v;i++){
      for(auto it: adj[i]){
        indegree[it]++;
      }}
    queue<int> q;
      for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(indegree[i]);
        }
      }

      int cnt=0;
      while (!q.empty())
      {
         int node=q.front();
           q.pop();
           cnt++;
           for(auto i: adj[node])
           {
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);            }
           }
      }
      if(cnt==v) return false;

return true;
 }
};

int main(){
  vector<int> adj[6]={{},{2},{3},{4,5},{2},{}};
  int v=6;
  solution obj;
    bool ans=obj.check(v,adj);
    if(ans) cout<<"true";
    else  cout<<"false";
    cout<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>  bfs(int n,vector<int> adj[]){
    int vis[n]={0};
    vis[1]=1;
    queue<int> q;
    q.push(1);
    vector<int> bfs;
    while (!q.empty())
    {
        int node=q.front();
        q.pop();
       bfs.push_back(node);
       for(auto itr:adj[node]){
          if(!vis[itr]){
            vis[itr]=1;
            q.push(itr);
          }
       }
    }
    
 return bfs;
}
void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
void dfs(int node ,vector<int> adj[],int vis[] ,vector<int> &ls){
    vis[node]=1;
    ls.push_back(node);
    for(auto i: adj[node]){
        if(!vis[i]){
            dfs(i,adj,vis,ls);
        }
    }
     
  
}
vector<int> dfsofgraph(int n,vector<int> adj[]){
    int vis[n]={0};
    int start=0;
    vector<int>ls;
    dfs(start,adj,vis,ls);
 return  ls;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
       // a[v].push_back(u);

    }
    //using itr  adjancy matrix
     for(int i=1;i<=n;i++){
        cout<<"vertex=>"<<i<<":";
        for(auto x:a[i]){
            cout<<"->"<<x;
        }
        cout<<endl;
    }
    
  //  vector<int> x=bfs(n,a);
 
    

    vector<int> y= dfsofgraph(n,a);
   printAns(y);


return 0;
}
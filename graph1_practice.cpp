#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> bfs(int n,vector<int>adj){
    int vis[n]={0};
    vis[0]=1;
    queue<int> q;
    q.push(0);
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
    for(auto i:bfs){
        cout<<i<<" ";
    }
    return bfs;
}
int main(){
int m,n;
cout<<"enter the input"<<endl;
cin>>m>>n;
int arr[m+1][n+1]={0};
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    arr[u][v]=1;
    arr[v][u]=1;
}

for(int i=1;i<=n;i++ )
{
    for(int j=1;j<=n;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
 cout<<"for bfs traversal"<<endl;
 bfs(n,)
}
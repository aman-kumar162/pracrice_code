#include <bits/stdc++.h>
using namespace std;
/*
class Solution {
  private: 
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1; 
        ls.push_back(node); 
        // traverse all its neighbours
        for(auto it : adj[node]) {
            // if the neighbour is not visited
            if(!vis[it]) {
                dfs(it, adj, vis, ls); 
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        int start = 0;
        // create a list to store dfs
        vector<int> ls; 
        // call dfs for starting node
        dfs(start, adj, vis, ls); 
        return ls; 
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    vector <int> adj[5];
    
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution obj;
    vector <int> ans = obj.dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}*/
int edge[10][10],size,item;
char vertex[10];
int vis[10],d_time[10],f_time[10];
int i,j,t=0;
void dfs_visit(int);
void build_graph(){
   cout<<"enter total num vertices ";
   cin>>size;
   cout<<"enter vertices  ";
   for (i=0;i<size;i++){
     cin>> vertex[i];
   }
   cout<<"enter the adj mat";
   for (i=0;i<size;i++){
      for(j=0;j<size;j++){
        cin>>edge[i][j];
      }
   }
   cout<<" the adj mat";
   for (i=0;i<size;i++){
      for(j=0;j<size;j++){
        cout<<edge[i][j]<<"    ";
      }
      cout<<endl;
   }
}
void dfs(){
    for(i=0;i<size;i++){
        vis[i]=0;
    }
    for(j=0;j<size;j++){
        if(!vis[j]){
            dfs_visit(j);
        }
    }
}
void dfs_visit(int vertex){
    t=t+1;
    d_time[vertex]=t;
    vis[vertex]=1;
    for(i=0;i<size;i++){
        if(edge[vertex][i]==1 && !vis[i]){
            dfs_visit(i);
        }
       
    }
    t=t+1;
    f_time[vertex]=t;
}
int main(){
       build_graph();
       dfs();
       cout<<"somethi       d time        finish_t"
       <<endl;
       for(int i=0;i<size;i++){
        cout<<"   "<<vertex[i]<<"        "<<d_time[i]<<"      "<<f_time[i]<<endl;
       }
}
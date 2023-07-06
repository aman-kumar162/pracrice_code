#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int spanningTree(int s,vector<vector<int>> adj[]){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(s,0);
        pq.push({0,4});
        int sum=0;
        while(!pq.empty()){
         auto it = pq.top();
         pq.pop();
         int node=it.second;
         int wt=it.first;
         if(vis[node]==1) continue;

         vis[node]=1;
         sum+=wt;
         for(auto it: adj[node]){
            int adjnode=it[0];
            int edgw=it[1];
            if(!vis[adjnode])pq.push({edgw,adjnode});
         }
        }
    return sum;
    }
    

};

int main(){
  int v=5;
  vector<vector<int>> edges={{0,1,2},{0,2,1},{1,2,1},{2,3,2},{3,4,1},{4,2,2}};
  vector<vector<int>> adj[v];
  for(auto it: edges){
    vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	Solution obj;
	int sum = obj.spanningTree(v, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}

#include<bits/stdc++.h>
using namespace std;
 class Solution{
 public:
vector<int> shortest(vector<vector<int>> adj[],int V,int S){
 priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialising distTo list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> distTo(V, INT_MAX);

        // Source initialised with dist=0.
        distTo[S] = 0;
        pq.push({0, S});

        // Now, pop the minimum distance node first from the min-heap
        // and traverse for all its adjacent nodes.
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            // Check for all adjacent nodes of the popped out
            // element whether the prev dist is larger than current or not.
            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
    
                    // If current distance is smaller,
                    // push it into the queue.
                    pq.push({dis + w, v});
                }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        return distTo;
    }

 };


int main(){
    vector<vector<int>> edge={{0,1,1},{0,2,6},{1,2,3},{1,0,1},{2,1,3},{2,0,6}};
    vector<vector<int>> adj[3];
       for(int i=0;i<6;i++){
        int u=edge[i][0];
        int v=edge[i][1];
        int wt=edge[i][2];
        adj[u].push_back({v,wt});
      }

    Solution obj;
  int v=3;
  int src=2;
    vector<int> ans=obj.shortest(adj,v,src);

     for (int i = 0; i < v; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    bool check(int ind,int v,vector<int> adj[],int color[]){
        queue<int> q;
        color[ind]=0;
        q.push(ind);
        while (!q.empty())
        {int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(color[it]=-1){
                color[it]!=color[node];
                q.push(it);
            }
            else if (color[it]==color[node]){
                return false;
            }
        }
            /* code */
        }
     return true;   
    }

public:
  bool isbipertite(int v,vector<int> adj[]){
    int color[v];
    for(int i=0;i<v;i++){
        color[i]=-1;
    }
    for (int i=0;i<v;i++){
        if(color[i]==-1){
            if(check(i,v,adj,color)==false) return false;

        }
    }
    return true;
  }

};
void addedge(vector<int> adj[] ,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    Solution obj;
    vector<int> adj[4];
    addedge(adj,0,2);
    addedge(adj,0,3);
    addedge(adj,2,3);
    addedge(adj,3,1);
    bool ans=obj.isbipertite(4,adj);
    if(ans)cout << "1\n";
	else cout << "0\n";  
	
	return 0;




}
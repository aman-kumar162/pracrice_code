#include<bits/stdc++.h>
using namespace std;
class solution{
private:
    bool dfs(int v,vector<int> adj[],int vis[],int pathvis[],int check[]){
        vis[v]=1;
        pathvis[v]=1;
        check[v]=0;
        for(auto it: adj[v]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathvis,check)==true){
                    check[v]=0;
                    return true;

                }
            }
            else if(pathvis[it]){
                check[v]=0;
                return true;
            }
        }
        check[v]=1;
        pathvis[v]=0;
        return false;
    }  

public:

 vector<int> eventual(int v,vector<int> adj[]){
   int vis[v]={0};
   int pathvis[v]={0};
   int check[v]={0};
   vector<int> savenode;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,adj,vis,pathvis,check);
        }
    }
    	for (auto i: check) {
			if (check[i] == 1) savenode.push_back(i);
		}
		return savenode;
 }

};

int main(){
vector<int>  adj[12]={{1},{2},{3},{4,5},{6},{6},{7},{},{1,9},{10},{8},{9}};
int v=12;
solution obj;
  vector<int> savenode=obj.eventual(v,adj);


  for(auto it: savenode){
    cout<< it<< " ";
  }
 return 0;
}
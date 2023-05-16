#include<bits/stdc++.h>
using namespace std;

class Solution{
 public:   
  int enclave(vector<vector<int>> &grid){
      int m=grid.size();
      int n=grid[0].size();
      int vis[m][n]={0};
      queue<pair<int,int>> q;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0 || i==m-1 ||j==n-1){
                if(grid[i][j]==1){
                     q.push({i,j});
                     vis[i][j]=1;
                }
            }
        }
      }
      int cnt=0;
      int row[]={-1,0,1,0};
      int col[]={0,1,0,-1};
      while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                  int nrow=r+row[i];
                  int ncol=c+col[i];
                  if(nrow>=0 && nrow<m && ncol>=0 && nrow<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                  }
            }
      }

      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]==0 && grid[i][j]==1)
            {
                cnt++;
            }
        }
      }
     return cnt;

  }

};


int main(){
    vector<vector<int>> grid{{0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};
                             
     Solution obj;
       cout<< obj.enclave(grid);                          
}
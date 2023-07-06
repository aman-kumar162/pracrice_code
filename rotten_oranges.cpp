#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
      int rotten(vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        int cntFresh=0;
        queue <pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  if(grid[i][j]==2){
                         q.push({{i,j},0});
                         vis[i][j]=2;
                  }
               else{
                  vis[i][j]=0;
               } 
              
               if (grid[i][j] == 1) cntFresh++;  


            }
        }
        int tm=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int cnt=0;
        while (!q.empty())
        {int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
          tm=max(tm,t);
          q.pop();
          for(int i=0;i<4;i++){
            int nrow=r+dr[i];
            int ncol=c+dc[i];
              if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1 ){
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol]==2;
                cnt++;
              } }

        }
      
     if (cnt != cntFresh) return -1;
     return tm;
      }

};

int main(){
 
      vector<vector<int>> grid{{0,1,2},{0,1,2},{2,1,1}};
         solution obj;
      int ans=obj.rotten(grid);
      cout<<ans<<endl;
      return 0;

}

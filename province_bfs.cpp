#include<bits/stdc++.h>
using namespace std;
class solution{
private:
   void bfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &grid){
        vis[i][j]=1;
        queue<pair<int,int>> q;
          q.push({i,j});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int nrow=-1;nrow<=1;nrow++){
                for(int ncol=-1;ncol<=1;ncol++){
                    int latrow=row+nrow;
                    int latcol=col+ncol;
                    if(latrow>=0 && latcol>=0 && latrow<n &&
                     latcol<m && !vis[latrow][latcol] && 
                     grid[latrow][latcol]=='1'){
                        vis[latrow][latcol]=1;
                        q.push({latrow,latcol});
                    }
                }
            }
        }

   }
public:
    int island(vector<vector<char>> &grid){
       
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
         int cnt=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]== '1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
         }
        return cnt;
    }

};

int main(){
    
   vector<vector<char>> grid{
       {'0','1','1','0','0','0','0'},
       {'0','0','1','0','1','1','1'},
       {'1','0','0','0','0','0','0'}
   };
  solution obj;
  cout<<"the number of provinces is"<<endl;
   cout<<obj.island(grid)<<endl;
 return 0;
}
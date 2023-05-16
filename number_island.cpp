#include<bits/stdc++.h>
using namespace std;
class  solution {
private:
     void dfs(int i,int j,vector<vector<int>> & grid, vector<pair<int,int>> &vec,vector<vector<int>> &vis ,int r0,int c0){
        vis[i][j]=1;
        int inr=i-r0;
        int ind=j-c0;
        vec.push_back({inr,ind});
        int row=grid.size();
        int col=grid[0].size();
        int delro[]={-1,0,1,0};
        int delco[]={0,-1,0,1};
        for(int k=0;k<4;k++){
            int nrow= i+delro[k];
            int ncol= j+delco[k];
            if(nrow>=0 && nrow <row && ncol >=0 &&  ncol<col && vis[nrow][ncol]==0 && grid[nrow][ncol]==1  )
                dfs(nrow,ncol,grid,vec,vis,r0,c0);

        }

     }

public:
      int island(vector<vector<int>> & grid){
     int n=grid.size();
     int m=grid[0].size();
     vector<vector<int> >vis(n,vector <int> (m,0));

     set<vector<pair<int,int>>> st;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vector<pair<int,int>> vec;
            if(grid[i][j]==1 && vis[i][j]==0){
                dfs(i,j,grid,vec,vis,i,j);
             st.insert(vec);
            }
        }
     }
        return   st.size();
      }

};

int main()

{  vector<vector<int>>  grid{
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}};
  solution obj;
    cout<<  obj.island(grid);


}
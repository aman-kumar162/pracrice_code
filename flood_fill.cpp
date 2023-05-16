#include<bits/stdc++.h>
using namespace std;

class solution{
 private:
   void dfs(int sr,int sc,vector<vector<int>>&ans,vector<vector<int>>&image,int newcolor,int delrow[],int delcol[],int incolor)
   {
    ans[sr][sc]=newcolor;
    int n = image.size();
        int m = image[0].size();
        for(int i = 0;i<4;i++) {
            int nrow = sr + delrow[i]; 
            int ncol = sc + delcol[i]; 
            // check for valid coordinate 
            // then check for same initial color and unvisited pixel
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
            image[nrow][ncol] == incolor && ans[nrow][ncol] != newcolor) {
                dfs(nrow, ncol, ans, image, newcolor, delrow, delcol, incolor); }
   }
   }

public:

vector<vector<int>>  floodfill(vector<vector<int>> image,int sr,int sc,int newcolor){
   int incolor=image[sr][sc];
   vector<vector<int>>ans=image;
   int delrow[]={-1,0,+1,0};
   int delcol[]={0,+1,0,-1};
   dfs(sr,sc,ans,image,newcolor,delrow,delcol,incolor);
   return ans;
}

};

int main(){
    vector<vector<int>>image{
        {1,0,1},
        {1,1,0},
        {1,0,1}
    };
    solution obj;
    vector<vector<int>> ans=obj.floodfill(image,1,0,500);
   
   for(auto i:ans){
    for(auto j:i){
        cout<<j<<" ";
    }
    cout<<endl;

   }
   return 0;
}

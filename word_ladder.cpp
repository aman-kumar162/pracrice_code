#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
  int len(string s,string t,vector<string> wordlist){
    //queue initalisation 
    queue<pair<string,int>> q;
    //push the starting word
    q.push({s,1});
    unordered_set<string> st(wordlist.begin(),wordlist.end());
    st.erase(s);// pop out first element fron the set
    while(!q.empty()){
       string word=q.front().first;
       int steps=q.front().second;
       q.pop();
       if(word==t){
        return steps;

       }
       for(int i=0;i<word.size();i++){
            char original=word[i];
            for( char ch='a'; ch<='z';ch++) {
                word[i]=ch;
                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
            }
            word[i]=original;    
       }
    }
  return 0;
  }
};


int main(){
   vector<string> wordList={"des","der","dfr","dgt","dfs"};
   string strtword="des" ,targetword="dfr";
   Solution obj;
   int ans=obj.len(strtword,targetword,wordList);
   cout<<ans;
   return 0;


}
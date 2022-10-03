#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> printGraph(int v, vector<int> adj[]) {
        vector<vector<int>> ans(v,{0});
        for(int i=0;i<v;i++){
            ans[i][0] = i;
            for(auto j:adj[i]){
                ans[i].push_back(j);
            }
       }
    return ans;
        
    }
};

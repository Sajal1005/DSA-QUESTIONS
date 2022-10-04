#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        unordered_map<int,list<int>> adj;
         for(auto it : pre) {
         adj[it[1]].push_back(it[0]);
     }
        vector<int> ans;
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front = q.front();
            ans.push_back(front);
            q.pop();
            for(auto j:adj[front]){
                indegree[j]--;
                if(indegree[j]==0){
                    q.push(j);
                }
            }
        }
        if(ans.size()==n){
            return ans;
        }else{
            return {};
        }
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int> ans;
	    vector<int> indegree(v);

	    for(int i=0;i<v;i++){
	        for(auto j:adj[i]){
	            indegree[j]++;
	        }
	    }

	    queue<int> q;
	    for(int i=0;i<v;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
        
	    while(!q.empty()){
	        int front = q.front();
	        q.pop();
	        ans.push_back(front);
	        for(auto j:adj[front]){
	            indegree[j]--;
	            if(indegree[j]==0){
	                q.push(j);
	            }
	        }
	    }
	return ans;}
};
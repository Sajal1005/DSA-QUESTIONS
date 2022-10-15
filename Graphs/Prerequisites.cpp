#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& pre) {
	    
	    int count=0;
	    unordered_map<int,list<int>> adj;
	    vector<int> indegree(n);
	    for(int i=0;i<pre.size();i++){
	            adj[pre[i].second].push_back(pre[i].first);
	    }
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
	        count++;
	        q.pop();
	        for(auto j:adj[front]){
	            indegree[j]--;
	            if(indegree[j]==0){
	                q.push(j);
	            }
	        }
	    }
	    if(count==n){
	        return true;
	    }else{
	        return false;
	    }
	}
};
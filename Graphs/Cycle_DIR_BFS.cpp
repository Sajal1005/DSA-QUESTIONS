#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isCyclic(int v, vector<int> adj[]) {

        int count=0;
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
	        count++;
	        for(auto j:adj[front]){
	            indegree[j]--;
	            if(indegree[j]==0){
	                q.push(j);
	            }
	        }
	    }
        
	if(count==v){
	 return false;   
	}else{return true;}
	;
    }
};
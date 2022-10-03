#include<bits/stdc++.h>
using namespace std;


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
    vector<int> ans;
	unordered_map<int,list<int>> adj;
    unordered_map<int,int> visited;
    unordered_map<int,int> parent;
    for(int i=0;i<m;i++){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    
    //MAIN CODE
    queue<int> q;
    q.push(s);
    visited[s]=1;
    parent[s]=-1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto j:adj[front]){
            if(!visited[j]){
                q.push(j);
                visited[j]=1;
                parent[j]=front;
            }
        }
    }
    int curr=t;
    ans.push_back(curr);
    while(curr!=s){
        curr = parent[curr];
        ans.push_back(curr);
    }
    reverse(ans.begin(),ans.end());
    
    return ans;
	
}
#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        vector<int> dist(v,INT_MAX);

        queue<int> q;
        q.push(s);
        dist[s]=0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto j:adj[front]){
                if(dist[front]+j[1]<dist[j[0]]){
                    dist[j[0]]=dist[front]+j[1];
                    q.push(j[0]);
                }
            }
        }
        
        return dist;
        
    }
};
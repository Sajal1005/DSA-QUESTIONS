#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool isCycle(int v, vector<int> adj[]) {
        
        unordered_map<int,int> visited;
        unordered_map<int,int> parent;

        for(int i=0;i<v;i++){

            if(!visited[i]){
                queue<int> q;
                parent[i]=-1;
                q.push(i);
                visited[i]=1;

                while(!q.empty()){
                    int front = q.front();
                    q.pop();
                    
                    for(auto j:adj[front]){
                        if(visited[j]==1 && j!=parent[front]){
                            return true;
                        }else if(!visited[j]){
                            q.push(j);
                            visited[j]=1;
                            parent[j]=front;
                        }
                    }
                }
                
            }
        }
    return false;}
};


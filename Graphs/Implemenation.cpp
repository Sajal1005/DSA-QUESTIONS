#include<bits/stdc++.h>
using namespace std;

void add(unordered_map<int, list<int>> &adj, int u, int v){
    adj[u].push_back(v);
    //if undirected
    adj[v].push_back(u);
}

void print(unordered_map<int, list<int>> &adj, int n){
    for(auto i:adj){
        cout<<i.first<<" ";
        for(auto j:i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    unordered_map<int, list<int>> adj;
    int n;
    cin>>n;
    int m;
    cin>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        add(adj,u,v);
    }
    print(adj,n);
    return 0;
}
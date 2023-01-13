#include<bits/stdc++.h>
#include<utility>
using namespace std;


void dfs(int node,vector<int> *adj,vector<int> &ans,vector<bool> &visited){
	visited[node]=true;
	ans.push_back(node);

	for(int i:adj[node]){
		if(!visited[i]){
			dfs(i,adj,ans,visited);
		}
	}
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;
    // bfs(6,adj,ans,n);

    std::vector<bool> visited(n+1,false);
    dfs(1,adj,ans,visited);
    for(int i:ans){
    	cout<<i<<" ";
    }
    return 0;
    
}

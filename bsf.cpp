#include<bits/stdc++.h>
#include<utility>
using namespace std;
void bfs(int startnode,vector<int> *adj,vector<int> &ans,int n){
	queue<int> q;
	vector<bool> visited(n+1,false);
	q.push(startnode);
    visited[startnode]=true;
	while(!q.empty()){

		int t=q.front();
		q.pop();
		ans.push_back(t);

		for(int i:adj[t]){
			if(!visited[i]){
				visited[i]=true;
				q.push(i);
			}
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
    bfs(5,adj,ans,n);
    for(int i:ans){
    	cout<<i<<" ";
    }
    return 0;
    
}

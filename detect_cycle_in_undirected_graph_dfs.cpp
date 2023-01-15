//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
   
    bool dfs(int node,int parent,vector<int> *adj,vector<bool> &visited){
        visited[node]=true;
        bool detect=false;
        for(int child:adj[node]){
            if(visited[child] && child!=parent){
                return true;
            }
            if(!visited[child]){
                detect=detect|dfs(child,node,adj,visited);
            }
        }
        return detect;
    }
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool> visited(V,false);
        bool detect=false;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                // detect=detect|bfs(i,adj,visited);
                detect=detect|dfs(i,-1,adj,visited);
                
            }
        }
        return detect;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        // Edge case: same node
        if(source == destination) return true;

        // Step 1: Build adjacency list
        vector<vector<int>> adj(n);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }

        // Step 2: BFS setup
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(source);
        visited[source] = true;

        // Step 3: BFS traversal
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            if(node == destination)
                return true;

            for(int neighbor : adj[node]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // Step 4: If destination not reached
        return false;
    }
};

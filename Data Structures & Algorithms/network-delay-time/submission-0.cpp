class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // 3. Distance array initialized to infinity
        vector<int> dist(n + 1, 1e9);
        
        // Start at source node k
        dist[k] = 0;
        pq.push({0, k});
        
        // 4. Run Dijkstra
        while (!pq.empty()) {
            int curr_dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            // Optimization: If we already found a shorter way to this node, skip it
            if (curr_dist > dist[u]) continue;
            
            // Explore all neighbors of u
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                // Relaxation step
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // 5. Find the maximum shortest path
        int max_time = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == 1e9) return -1; // Node i was unreachable
            max_time = max(max_time, dist[i]);
        }
        
        return max_time;
    }
};
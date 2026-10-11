class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 1. Build Adjacency List with Min-Heaps to maintain lexical order
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        
        for (auto& ticket : tickets) {
            string from = ticket[0];
            string to = ticket[1];
            adj[from].push(to);
        }
        
        vector<string> result;
        
        // 2. Start DFS from JFK
        dfs("JFK", adj, result);
        
        // 3. The result is built backwards, so reverse it
        reverse(result.begin(), result.end());
        
        return result;
    }
    
private:
    void dfs(string airport, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& adj, vector<string>& result) {
        // Keep flying as long as there are available outbound tickets from this airport
        while (!adj[airport].empty()) {
            // Get the alphabetically smallest next destination
            string next_airport = adj[airport].top();
            adj[airport].pop(); // "Use" the ticket by removing it
            
            // Recursively fly to the next airport
            dfs(next_airport, adj, result);
        }
        
        // We are stuck (no more outbound flights). Add this airport to the result.
        result.push_back(airport);
    }
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }
        vector<int> state(numCourses, 0);
        
        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0) {
                if (!dfs(i, adj, state)) {
                    return false; 
                }
            }
        }
        
        return true;
    }
    
private:
    bool dfs(int course, const vector<vector<int>>& adj, vector<int>& state) {
        if (state[course] == 1) return false;
        if (state[course] == 2) return true;  
        state[course] = 1;
        for (int pre : adj[course]) {
            if (!dfs(pre, adj, state)) {
                return false;
            }
        }
        state[course] = 2;
        return true;
    }
};
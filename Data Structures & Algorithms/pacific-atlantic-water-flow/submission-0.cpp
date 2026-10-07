#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        // Matrices to track cells that can reach each ocean
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        
        // 1. Run DFS from the top (Pacific) and bottom (Atlantic) rows
        for (int c = 0; c < n; c++) {
            dfs(heights, pac, 0, c, heights[0][c]);       // Top row
            dfs(heights, atl, m - 1, c, heights[m - 1][c]); // Bottom row
        }
        
        // 2. Run DFS from the left (Pacific) and right (Atlantic) columns
        for (int r = 0; r < m; r++) {
            dfs(heights, pac, r, 0, heights[r][0]);       // Left column
            dfs(heights, atl, r, n - 1, heights[r][n - 1]); // Right column
        }
        
        // 3. Find cells that are true in both matrices
        vector<vector<int>> result;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pac[r][c] && atl[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        
        return result;
    }

private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c, int prevHeight) {
        // Base case: check out-of-bounds, already visited, or if we can't flow "up"
        if (r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size() || 
            visited[r][c] || heights[r][c] < prevHeight) {
            return;
        }
        
        // Mark cell as visited by this ocean
        visited[r][c] = true;
        
        // Explore all 4 directions recursively
        dfs(heights, visited, r + 1, c, heights[r][c]);
        dfs(heights, visited, r - 1, c, heights[r][c]);
        dfs(heights, visited, r, c + 1, heights[r][c]);
        dfs(heights, visited, r, c - 1, heights[r][c]);
    }
};
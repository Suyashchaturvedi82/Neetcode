#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] != 2147483647) {
                    continue;
                }
                grid[nr][nc] = grid[r][c] + 1;
                
                q.push({nr, nc});
            }
        }
    }
};
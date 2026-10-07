#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        for (int r = 0; r < m; r++) {
            if (board[r][0] == 'O') dfs(board, r, 0);          
            if (board[r][n - 1] == 'O') dfs(board, r, n - 1); 
        }
        for (int c = 0; c < n; c++) {
            if (board[0][c] == 'O') dfs(board, 0, c);          
            if (board[m - 1][c] == 'O') dfs(board, m - 1, c);  
        }
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X'; 
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O'; 
                }
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int m = board.size();
        int n = board[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] != 'O') {
            return;
        }
        board[r][c] = 'T';
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
};
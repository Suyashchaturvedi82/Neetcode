#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.')); // 
        vector<bool> col(n, false);
        vector<bool> posDiag(2 * n - 1, false); 
        vector<bool> negDiag(2 * n - 1, false); 
        
        backtrack(0, n, col, posDiag, negDiag, board, res);
        return res;
    }
    
private:
    void backtrack(int r, int n, vector<bool>& col, vector<bool>& posDiag, vector<bool>& negDiag, vector<string>& board, vector<vector<string>>& res) {
        if (r == n) {
            res.push_back(board);
            return;
        }
        
        for (int c = 0; c < n; c++) {
            if (col[c] || posDiag[r + c] || negDiag[r - c + n - 1]) {
                continue; 
            }
            board[r][c] = 'Q';
            col[c] = posDiag[r + c] = negDiag[r - c + n - 1] = true;
            backtrack(r + 1, n, col, posDiag, negDiag, board, res);
            

            board[r][c] = '.';
            col[c] = posDiag[r + c] = negDiag[r - c + n - 1] = false;
        }
    }
};
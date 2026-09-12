class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>rows[9];
        unordered_set<char>cols[9];
        unordered_set<char>boxes[9];
        for(int i =0;i<9;i++){
            for(int j =0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                char nums= board[i][j];
                if(rows[i].count(nums)){
                    return false;
                }
                if(cols[j].count(nums)){
                    return false;
                }
                int box = (i/3)*3+(j/3);
                if(boxes[box].count(nums)){
                    return false;
                }
                rows[i].insert(nums);
                cols[j].insert(nums);
                boxes[box].insert(nums);
            }
        }
        return true;
    }
};

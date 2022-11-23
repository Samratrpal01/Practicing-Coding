class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    vector<unordered_map<char, bool>> rows(9);
    vector<unordered_map<char, bool>> cols(9);
    vector<unordered_map<char, bool>> cells(9);
        
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
                if(board[i][j] <= '9' && board[i][j] >= '1')
                    {
                        if(rows[i].count(board[i][j]) || cols[j].count(board[i][j]) || cells[3 * (j / 3) + (i / 3)].count(board[i][j]))
                            return false;
                        else
                            {
                                    rows[i][board[i][j]] = true;
                                    cols[j][board[i][j]] = true;
                                    cells[3 * (j / 3) + (i / 3)][board[i][j]] = true;
                            }
                    }
    return true;
    }
};
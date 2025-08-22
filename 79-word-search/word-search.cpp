class Solution {
public:
     bool WSearch(int row,int col,int idx,vector<vector<char>>& board,string& word){
        if(idx == word.length()){
            return true;
        }
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()){   //out of bound
            return false;
        }
        if(word[idx] != board[row][col]){     //invalid letter
            return false;
        }
        if(board[row][col] == '#'){
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '#';
        if(WSearch(row - 1, col, idx + 1, board, word) ||
            WSearch(row + 1, col, idx + 1, board, word) ||
            WSearch(row, col - 1, idx + 1, board, word) ||
            WSearch(row, col + 1, idx + 1, board, word)){
                return true;
            }
        board[row][col] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size(); i++){
            for(int j =0; j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    bool found = WSearch(i,j,0,board,word);
                    if(found) return true;
                }
            }
        }
        return false;
    }
};
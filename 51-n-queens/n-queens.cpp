class Solution {
public:
    int N;
    vector<vector<string>> result;
    unordered_set<int> pcol;
    unordered_set<int> dig;
    unordered_set<int> antidig;

    void solve(vector<string>& board,int row){
        if(row >=  N){
            result.push_back(board);
            return;
        }
        for(int col = 0; col <N;col++){
            int digConst = row+col;
            int AntidigConst = row-col;
            if(pcol.find(col) != pcol.end() || dig.find(digConst) != dig.end() || 
                antidig.find(AntidigConst) != antidig.end())
            {
                continue;  //if the col us alreay present ot dig or antidig
            }
            board[row][col] = 'Q';
            pcol.insert(col);
            dig.insert(digConst);
            antidig.insert(AntidigConst);

            solve(board,row+1);
            board[row][col] = '.';
            pcol.erase(col);
            dig.erase(digConst);
            antidig.erase(AntidigConst);    
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        N= n;
        vector<string> board(n,string(n,'.')); //board[i] → gives you the i-th row (a string) // 
        solve(board,0);    //board[i][j] → gives you the j-th character inside that string, i.e., the column.
        return result;
        
    }
};
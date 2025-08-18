class Solution {
public:
    int N;
    vector<vector<string>> result;
    unordered_set<int> cols;
    unordered_set<int> dig;
    unordered_set<int> Antidig;

    void solve(vector<string>& board,int row){
        if(row >= N){
            result.push_back(board);
            return;
        }
        for(int col = 0; col <N; col++){
            int digConst = row+col;
            int AntidigConst = row-col;
            if(cols.find(col) != cols.end() || dig.find(digConst) != dig.end()
               || Antidig.find(AntidigConst) != Antidig.end())
            {
                continue;
            }
            board[row][col] = 'Q';
            cols.insert(col);
            dig.insert(digConst);
            Antidig.insert(AntidigConst);
            solve(board,row+1);

            //undo
            board[row][col] = '.';
            cols.erase(col);
            dig.erase(digConst);
            Antidig.erase(AntidigConst);

        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        N = n;
        solve(board,0);
        return result;
    }
};
class Solution {
public:
    int MaxOpen;
    int MaxClose;
    vector <string> result;

    void Gparent(string &temp,int open, int close){
        if(open >= MaxOpen && close>= MaxClose){
            result.push_back(temp);
            return;
        }
        if(open < MaxOpen){
            temp += "(";
            Gparent(temp,open+1,close);
            temp.pop_back();
        }
        if(close < open){
            temp += ")";
            Gparent(temp,open,close+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        MaxOpen = n;
        MaxClose = n;
        string temp;
        Gparent(temp,0,0);
        return result;
    }
};
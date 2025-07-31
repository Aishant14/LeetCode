class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        int n = goal.length();
        string fstr = s+s;
        for(int i =0; i<n; i++){
            string temp  = fstr.substr(i,n);
            if(temp == goal) return true;
        }
        return false;
    }
};
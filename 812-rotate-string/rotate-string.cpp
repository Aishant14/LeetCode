class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        int n = s.length();
        for(int i =1; i<=s.length(); i++){
            string temp = s;
            reverse(temp.begin(), temp.end());
            reverse(temp.begin(), temp.begin() +(n-i));
            reverse(temp.begin() +(n-i), temp.end());
            if(temp == goal){
                return true;
            }
        }
        return false;
    }
};
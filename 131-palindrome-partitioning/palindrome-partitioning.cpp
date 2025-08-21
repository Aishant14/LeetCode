class Solution {
public:
    vector<vector<string>> result;

    bool isPalindrome(string s, int start, int end){
        while(end>= start){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void PPart(string s,vector<string>& temp,int idx){
        if(idx >= s.length()){
            result.push_back(temp);
        }
        for(int i = idx; i<s.length(); i++){
            if(isPalindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                PPart(s,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        PPart(s,temp,0);
        return result;
    }
};
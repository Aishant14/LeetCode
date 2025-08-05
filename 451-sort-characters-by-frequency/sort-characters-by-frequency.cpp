class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp1;
        int n = s.length();
        for(char ch: s){
            mp1[ch]++;
        }
        vector<vector<char>> bucket (n+1);
        for(auto pair : mp1){
            char ele = pair.first;
            int val = pair.second;
            bucket[val].push_back(ele);
        }
        string res = "";
        for(int i = n; i>= 0; i--){
            for(char temp : bucket[i])
            {
                res = res + string(i,temp);
            }
        }
        return res;
    }
    
};
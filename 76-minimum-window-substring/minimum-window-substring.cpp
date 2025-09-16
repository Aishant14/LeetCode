class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int n = s.length();
        int reqCount = t.length();
        int minWindow = INT_MAX;
        int minStart = 0;
        if(s.length() < t.length()) return "";
        for(char ch: t){
            mp[ch]++;
        }
        int i =0, j=0;

        while(j<n){
            char ch_j = s[j];
            if(mp[ch_j] > 0){
                reqCount--;
            }
            mp[ch_j]--;
            while(reqCount == 0){
                if(j-i+1 < minWindow){
                    minWindow = j-i+1;
                    minStart = i;
                }
                char ch_i = s[i];
                mp[ch_i]++;
                if(mp[ch_i]>0){
                    reqCount++;
                }
                i++;
            }
            j++;
        }

        if(minWindow == INT_MAX){
            return "";
        }else{
            return s.substr(minStart,minWindow);
        }
        
    }
};
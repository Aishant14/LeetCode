class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> freq1;
        for (char ch : s){
            freq1[ch]++;
        }
        unordered_map<char, int> freq2;
        for (char ch : t){
            freq2[ch]++;
        }
        for(int i =0 ;i<s.length(); i++){
            char temp = t[i];
            if(freq2.find(temp) != freq2.end()){
                if(freq1[temp] != freq2[temp]){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};
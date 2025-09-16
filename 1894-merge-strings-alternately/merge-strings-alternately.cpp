class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int i =0;
        string res = "";
        while(i < len1 && i < len2){
            res+= word1[i];
            res += word2[i];
            i++;
        }
        while(i<len1){
            res += word1[i];
            i++;
        }
        while(i<len2){
            res += word2[i];
            i++;
        }
        return res;
    }
};
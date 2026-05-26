class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> low;
        unordered_set<char> up;

        for(char ch : word){
            if(islower(ch)){
                low.insert(ch);
            }
            else{
                up.insert(tolower(ch));
            }
        }
        int res = 0;
        for(char ch : low){
            if(up.count(ch)){
                res++;
            }
        }
        return res;
    }
};
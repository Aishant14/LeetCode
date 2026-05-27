class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> lowermp;
        unordered_map<char,int> uppermp;
        for(int i =0; i<word.length(); i++){
            char ch = word[i];
            if(islower(ch)){
                lowermp[ch] = i;
            }
            else{
                if(!uppermp.count(tolower(ch))){
                    uppermp[tolower(ch)] = i;
                }
            }
        }
        int res = 0;
        for(auto pair : lowermp){
            char ch = pair.first;
            int lowerpos = pair.second;
            if(uppermp.find(ch) != uppermp.end()){
                int upperpos = uppermp[ch];
                if(lowerpos < upperpos){
                    ++res;
                }
            }
        }
        return res;

    }
};
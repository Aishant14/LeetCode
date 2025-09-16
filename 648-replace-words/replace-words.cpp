class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int> mp;
        for(string str : dictionary){
            mp[str]++;
        }
        vector<string> ans;
       stringstream ss(sentence);
       string word;
       while(ss >> word){
        bool rep = false;
        string prefix = "";
            for(int i =0; i<word.size(); i++){
                prefix += word[i];
                if(mp.count(prefix)){
                    ans.push_back(prefix);
                    rep = true;
                    break;
                }
            }
            if(rep == false){
                ans.push_back(word);
            }
       }
       string res = "";
       for(int i =0; i<ans.size(); i++){
            res += ans[i];
            if(i != ans.size()-1){
                res+= " ";
            }
       }
       return res;

    }
};
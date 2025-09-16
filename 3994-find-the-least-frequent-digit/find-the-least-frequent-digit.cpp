class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int,int> mp1;
        while(n > 0){
            int val = n%10;
            mp1[val]++;
            n /= 10;
        }
        int freq = INT_MAX;
        int res = INT_MAX;
        for(auto pair: mp1){
            if(pair.second < freq || (pair.second == freq && pair.first < res)){
                freq = pair.second;
                res = pair.first;
            }
        }
        return res;
    } 
};
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i : nums){
            mp[i]++;
        }
        int sum = 0;
        for(auto &pair: mp){
            if(pair.second %k == 0){
                sum += pair.first * pair.second;
            }
        }
        return sum;
    }
};
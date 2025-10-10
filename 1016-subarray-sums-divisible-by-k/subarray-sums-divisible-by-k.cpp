class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum =0;
        int res = 0;
        mp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int rem = ((sum % k) + k) % k;
            if(mp.find(rem) != mp.end()){
                res += mp[rem];
            }
            mp[rem]++;
        }
        return res;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 1;
        int lastele = INT_MIN;
        int res = 1;
        if(nums.empty())return 0;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] == lastele+1){
                lastele = nums[i];
                count++;
            }
            else if(nums[i] == lastele){
                continue;
            }
            else{
                lastele = nums[i];
                if(count > res){
                    res = count;
                }
                count = 1;
            }
        }
        if(count > res){
            res = count;
        }
        return res;
    }
};
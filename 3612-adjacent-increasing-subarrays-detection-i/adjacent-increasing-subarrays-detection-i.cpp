class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int start = 0; start + 2*k <= n; start++) {
            bool flag1 = true;
            bool flag2 = true;

            // check first subarray [start .. start + k - 1]
            for(int i = start; i < start + k - 1; i++) {
                if(nums[i] >= nums[i + 1]) {
                    flag1 = false;
                    break;
                }
            }

            // check second subarray [start + k .. start + 2*k - 1]
            for(int j = start + k; j < start + 2*k - 1; j++) {
                if(nums[j] >= nums[j + 1]) {
                    flag2 = false;
                    break;
                }
            }

            if(flag1 && flag2)
                return true;
        }

        return false;
    }
};

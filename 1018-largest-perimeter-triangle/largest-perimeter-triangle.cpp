class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int res = INT_MIN;
        for(int i =0; i<nums.size()-2; i++){
            int large = nums[i];
            int otherside = nums[i+1] + nums[i+2];
            if(otherside > large){
                if(res < otherside + large){
                    res = otherside+ large;
                }
            }
        }
        if(res == INT_MIN){
            return 0;
        }
        return res;

    }
};
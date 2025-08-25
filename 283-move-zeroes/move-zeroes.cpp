class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0;
        for(int real = 0; real < nums.size(); real++){
            if(nums[real] != 0){
                swap(nums[real],nums[zero]);
                zero++;
            }
        }
    }
};
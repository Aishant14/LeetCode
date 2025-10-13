class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum =0;
        int curr = nums[0];
        int freq = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == curr){
                freq++;
            }
            else{
                if(freq%k == 0){
                    sum += freq*curr;
                }
                curr = nums[i];
                freq = 1;
            }
        }
        if(freq%k == 0){
            sum += freq*curr;
        }
        return sum;

    }
};
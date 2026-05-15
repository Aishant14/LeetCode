class Solution {
public:
    bool isGood(vector<int>& nums) {
        int large = -1;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] > large){
                large = nums[i];
            }
        }

        vector <int> row(large+1,0);

        for(int i =0; i<nums.size(); i++){
            row[nums[i]]++;    
        }
        bool large_check = false;
        if(row[large] == 2){
            large_check = true;
        }
        int validate = true;
        
        for(int i = 1; i<large; i++){
            if(row[i] != 1){
                validate = false;
                break;
            }
        }
        return large_check && validate;

    }
};
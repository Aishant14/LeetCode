class Solution {
public:
    vector<vector<int>> result;
     void mySubset(vector<int>& nums,vector<int>& temp, int idx){
        result.push_back(temp);
        for(int i = idx; i<nums.size(); i++){
            temp.push_back(nums[i]);
            mySubset(nums,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        mySubset(nums,temp,0);
        return result;
    }
};
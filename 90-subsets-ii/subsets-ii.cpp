class Solution {
public:
    vector<vector<int>> result;
    void Subset2(vector<int>& nums,vector<int>& temp,int idx){
        result.push_back(temp);
        for(int i = idx; i<nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            Subset2(nums,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        sort(nums.begin(),nums.end());
        Subset2(nums,temp,0);
        return result;
    }
};
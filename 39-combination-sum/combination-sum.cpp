class Solution {
public:
    vector<vector<int>> result;
    void CombSum(vector<int>& candi, int target,vector<int>& temp,int idx ,int sum){
        if(idx >= candi.size()){
            return;
        }
        if(sum == target){
            result.push_back(temp);
            return;
        }
        for( int i = idx; i<candi.size(); i++){
            if(sum < target){
                sum += candi[i];
                temp.push_back(candi[i]);
                CombSum(candi,target,temp,i,sum);
           }
           else if(sum> target){
                return;
           }
            sum -= candi[i];
            temp.pop_back();          
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int sum =0;
        CombSum(candidates,target,temp,0,sum);
        return result;
    }
};
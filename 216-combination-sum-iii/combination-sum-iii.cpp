class Solution {
public:vector<vector<int>> result;
    void CombSum3(vector<int>& num,vector<int>& temp,int lim ,int target, int sum, int idx){
        if(lim == 0 && sum == target){
            result.push_back(temp);
            return;
        }
        if(sum  > target){
            return;
        }
        for(int i = idx; i<num.size() && lim > 0; i++){
            sum += num[i];
            temp.push_back(num[i]);
            CombSum3(num,temp,lim-1,target,sum,i+1);

            sum -= num[i];
            temp.pop_back();

        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> num = {1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        CombSum3(num,temp,k,n,0,0);
        return result;
    }
};
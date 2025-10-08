class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans(spells.size());
        for(int i=0; i<spells.size(); i++){
            int left = 0, right = potions.size()-1;
            int minval = INT_MAX;
            while(left <= right)
            {
                int mid = left + (right-left)/2;
                if((long long)potions[mid]*spells[i] >= success){
                    right = mid-1;
                    minval = mid;
                }
                else{
                    left = mid+1;
                }
            }
            if(minval == INT_MAX){
                ans[i] = 0;
            }
            else{
            ans[i] = potions.size()-minval;
            }
            
        }
        return ans;
        
    }
};
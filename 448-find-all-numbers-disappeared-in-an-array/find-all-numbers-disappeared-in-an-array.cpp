class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int> mp1;
        for(int num: nums){
            mp1[num]++;
        }
        vector<int> miss;
        int count = 0;
        for(int i=1; i<= nums.size(); i++){
            if(mp1.find(i) == mp1.end()){
                miss.push_back(i);
            }
        }
        
        return miss;
    }
};
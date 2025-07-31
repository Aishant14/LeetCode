class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp1;
        for(int num: nums){
            mp1[num]++;
        }
        int n = nums.size();
        vector<vector<int>> buckets(n+1);

        for(auto pair : mp1){
            int freq = pair.second;
            int element = pair.first;
            buckets[freq].push_back(element);
        }
        vector<int> v1;
        for(int i = n; i>= 0 && v1.size() < k; i--){
            for(int ele: buckets[i]){
                v1.push_back(ele);
                if(v1.size() == k) break;
            }
        }

        return v1;

    }
};
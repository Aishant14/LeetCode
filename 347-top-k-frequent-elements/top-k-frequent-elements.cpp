class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num: nums){
            mp[num]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto pair : mp){
            int val = pair.first;
            int freq = pair.second;
            pq.push({freq,val});
        }
        vector<int> res;
        while(k> 0){
            auto top = pq.top();
            pq.pop();
            int val =top.second;
            res.push_back(val);
            k--;
        }
        return res;
    }
};
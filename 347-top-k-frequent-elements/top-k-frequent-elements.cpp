class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> mp1;
       int n = nums.size();  
       for(int num:nums){   // for pair number with their frequancy
            mp1[num]++;
       }

       vector<vector<int>> bucket (n+1); // creating bucket to hold elements
       for(auto pair : mp1){           //transfers elements to vector based on their frequancy;
            int element = pair.first;
            int freq = pair.second;
            bucket[freq].push_back(element);
        }
        vector <int> finalarr;                //vector will will hold the most freq element based on k
        for(int i=n; i >=0 && k > finalarr.size(); i--){
            for(int ele : bucket[i])
            {
                finalarr.push_back(ele);
                if(finalarr.size() == k) break;
            }
        }
        return finalarr;



    }
};
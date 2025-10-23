class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        //vector<int> great(n,-1);
        unordered_map<int,int> mp;
        for(int i =0; i <nums2.size(); i++){
            while(!st.empty() && st.top() < nums2[i]){

               // great[st.top()] = nums[i];
               mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        vector<int> res;
        for(int num: nums1){
            if(mp.count(num)){
                res.push_back(mp[num]);
            }
            else{
                res.push_back(-1);
            }
        }
        return res;
    }
};
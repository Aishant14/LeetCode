class Solution {
public:
    int trap(vector<int>& height) {
        stack <int> st;
        int water = 0;
        if(height.size() <= 2) return 0;

        for(int i =0; i<height.size(); i++){
            while(!st.empty() && height[i] > height[st.top()]){
                int curridx = st.top();
                st.pop();
                if(st.empty()){
                    break;
                }
                int leftidx = st.top();
                int width = i - leftidx -1;
                int boundheight = min(height[leftidx],height[i]) - height[curridx] ;
                water += boundheight*width;
            }
            st.push(i);
        }
        return water;
    }
};
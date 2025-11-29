class Solution {
public:
    vector<int> SmallerLeft(vector<int>& height,int n){
        stack<int> st;
        vector<int> res(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && height[st.top()] > height[i]){
                st.pop();
            }
            if(st.empty()){
                res[i] = -1;
            }
            else{
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }
    vector<int> SmallerRight(vector<int>& height,int n){
        stack<int> st;
        vector<int> res(n);
        for(int i=n-1; i>= 0; i--){
            while(!st.empty() && height[st.top()] >= height[i]){
                st.pop();
            }
            if(st.empty()){
                res[i] = n;
            }
            else{
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSL = SmallerLeft(heights,n);
        vector<int> NSR = SmallerRight(heights,n);

        int maxarea = INT_MIN;
        for(int i=0; i<n; i++){
            int l = NSL[i];
            int r = NSR[i];
            int width = r-l-1;
            int area = heights[i]*width;
            maxarea = max(area,maxarea);
        }
        return maxarea;
    }
};
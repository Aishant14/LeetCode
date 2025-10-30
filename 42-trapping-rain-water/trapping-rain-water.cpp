class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n);
        vector<int> rmax(n);
        int res =0;

        int currleftmax = height[0];
        for(int i =0; i<n; i++){
           currleftmax = max(height[i],currleftmax);
            lmax[i] = currleftmax;
        }

        int currightmax = height[n-1];
        for(int i = n-1; i>=0; i--){
           currightmax = max(height[i],currightmax);
           rmax[i] = currightmax;
            
        }
        for(int i =0; i<n; i++){
            res += min(lmax[i],rmax[i]) -height[i];
        }
        return res;

    }
};

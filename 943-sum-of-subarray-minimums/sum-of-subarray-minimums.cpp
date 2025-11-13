class Solution {
public:
    vector<int> togetNSL(vector<int> arr, int n){
        stack<int> st;
        vector<int> res(n);
        //Right min
        for(int i =0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()) res[i] = -1;
            else res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> togetNSR(vector<int> arr, int n){
        stack<int> st;
        vector<int> res(n);
        //Right min
        for(int i = n-1; i>= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) res[i] = n;
            else res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int M = 1e9 +7;
        vector<int>NSL = togetNSL(arr,n);
        vector<int>NSR = togetNSR(arr,n);
        long long sum = 0;
        for(int i=0; i<n; i++){
            // to find the number of sub array that have arr[i] as lowest number 
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;
            long long totalWays = ls*rs;
            long long totalsum =  totalWays*arr[i];
            sum = (sum + totalsum)%M; 
        }
        return (int)sum;
    }
};
class Solution {
public:
    vector<int> getNSL(vector<int> arr, int n) {
        vector<int> res(n);
        stack<int> leftst;
        for (int i = 0; i < n; i++) {

            while (!leftst.empty() && arr[i] < arr[leftst.top()]) {
                leftst.pop();
            }
            if (leftst.empty()) {
                res[i] = -1;
            } else {
                res[i] = leftst.top();
            }
            leftst.push(i);
        }
        return res;
    }
 vector<int> getNSR(vector<int> arr, int n) {
    vector<int> res(n);
    stack<int> rightst;
    for (int i = n - 1; i >= 0; i--) {

        while (!rightst.empty() && arr[i] <= arr[rightst.top()]) {
            rightst.pop();
        }
        if (rightst.empty()) {
            res[i] = n;
        } else {
            res[i] = rightst.top();
        }
    rightst.push(i);
    }
    return res;
}

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    int M = 1e9 + 7;
    vector<int> NSL = getNSL(arr, n);
    vector<int> NSR = getNSR(arr, n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long ls = i - NSR[i];
        long long rs =  NSL[i] -i;
        long long totalWays = ls * rs;
        long long totalsum = totalWays * arr[i];
        sum = (sum + totalsum) % M;
    }
    return (int)sum;
}
}
;
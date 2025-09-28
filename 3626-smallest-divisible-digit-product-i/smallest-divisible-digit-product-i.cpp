class Solution {
public:
    int fact(int temp){
         int val = 1; 
         while(temp > 0){
             val *= temp%10;
             temp /= 10;
        }
        return val;
    }
    int smallestNumber(int n, int t) {
        int res = INT_MIN;
        for(int i = n; i<= 100; i++){
            int temp2 = fact(i);
            if(temp2 % t == 0){
                return i;
            }
        }
        return 0;
    }
};
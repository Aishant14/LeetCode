class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        int sum = 0;
        return fib(n-1) + fib(n-2);
        
    }
};
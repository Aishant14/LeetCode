class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long myPow(long long x, long long dig){
        if(dig == 0){
            return 1;
        } 
        if(dig%2 ==0){
            long long half = myPow(x,dig/2)%MOD;
            return half*half%MOD;
        }
        else{
            return( x%MOD)*myPow(x,dig-1)%MOD;
        }
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = (n+1)/2;
        return myPow(4,odd)*myPow(5,even) % MOD;
    }
};
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        int EmptyB = numBottles;
        res += EmptyB;
        while(EmptyB >= numExchange){
            int FilledB = EmptyB / numExchange;
            EmptyB = EmptyB % numExchange;
            res += FilledB;
            EmptyB += FilledB;
        }
        return res;
    }
};
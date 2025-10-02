class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int EmptyB = numBottles;
        int res = EmptyB;
        int FillB = 0;
        while(FillB != 0 || EmptyB >= numExchange){
            if(EmptyB >= numExchange){
                EmptyB -= numExchange;
                numExchange++;
                FillB++;
                continue;
            }
            EmptyB += FillB;
            res += FillB;
            FillB = 0;
        }
        return res;
    }
};
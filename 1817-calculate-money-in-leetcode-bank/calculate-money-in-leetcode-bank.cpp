class Solution {
public:
    int totalMoney(int n) {
        int monday_money = 1;
        int sum = 0;
        while(n > 0){
            int money = monday_money;
            for(int i = 1; i<= min(n,7); i++){
                sum += money++;
            }
            n -= 7;
            monday_money++;
        }
        return sum;
    }
};
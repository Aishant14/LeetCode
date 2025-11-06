class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(num>0){
            int last=num%10;//0
            sum+=last;//0
            num/=10;//1
            if(num==0 && sum>=10){
                num=sum;
                sum=0;
            }
        }
        return sum;
    }
};
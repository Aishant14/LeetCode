class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int laser = 0;
        int floor = 0;
        for(int row =0; row<bank.size(); row++){
            int dev = 0;
            for(int col =0; col < bank[0].length(); col++){
                if(bank[row][col] == '1'){
                    dev++;
                }
            }
            if(dev != 0){
                laser += floor*dev;
                floor = dev;
            }
        }
        return laser;
    }
};
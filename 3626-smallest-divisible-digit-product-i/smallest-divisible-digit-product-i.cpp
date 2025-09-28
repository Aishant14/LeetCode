class Solution {
public:
    int smallestNumber(int n, int t){
        for(int i = n; i<= 100; i++){
            string str=to_string(i);
            int pro=0;
            if(str.length()>=2){
            int f=str[0]-'0';
            int s=str[1]-'0';
            pro=f*s;
            }
            else if(str.length()==1){
                pro=str[0]-'0';
            }
            if(pro%t==0) return i;
        }
        return 0;
    }
};
class Solution {
public:
    bool hasSameDigits(string s) {
        int i = 0;
        int len = s.length();
        while( len > 2){
            int a = s[i] -'0';
            int b = s[i+1] -'0';
            int sum = (a+b)%10;
            s[i] = sum + '0';
            i++;
            if(i  ==  s.length() -1){
                len--;
                i = 0;
            }
        }
        if( s[0] == s[1]) {
            return true;
        }
        return false;

    }
};
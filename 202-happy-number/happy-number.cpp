class Solution {
public:
    int fact(int n){
    int sum = 0;
    while(n > 0){
        int temp = n%10;
        sum += temp*temp;
        n /= 10;
    }
    return sum;
}
    bool isHappy(int n) {
        unordered_set<int> st;
        st.insert(n);
        while(n != 1){
            int curr = fact(n);
            if(st.find(curr) != st.end()){
                return false;
            }
            st.insert(curr);
            n = curr;
        }
        return true;
    }
};
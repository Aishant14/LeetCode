class Solution {
public:
    int maxDepth(string s) {
        stack <char> st;
        int res = 0;
        int curr = 0;
        for(auto ch : s){
            if(ch == '('){
                st.push('(');
                curr++;
                if(curr > res){
                    res = curr;
                }
            }
            else if (ch == ')'){
                st.pop();
                curr--;
            }
        }
        return res;


    }
};
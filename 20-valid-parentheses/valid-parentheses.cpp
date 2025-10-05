class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                //if(st.empty()) return false;
                if(st.empty()){
                    return false;
                }
                char temp=st.top();
                st.pop();
                if ((temp == '(' && ch != ')') ||
                    (temp == '[' && ch!= ']') ||
                    (temp == '{' && ch != '}')){

                    return false;
                } 
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
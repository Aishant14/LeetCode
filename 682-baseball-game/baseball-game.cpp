class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i=0; i<operations.size(); i++){
            if(operations[i] == "C"){
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(operations[i] == "D"){
                if(!st.empty()){
                    st.push(2*st.top());
                }
            }
            else if(operations[i] == "+"){
                if(st.size() >= 2){
                   int num1 = st.top();
                   st.pop();
                   int num2 = st.top();
                   st.push(num1);
                   st.push(num1+num2);
                }
            }
            else{
                int val = stoi(operations[i]);
                st.push(val);
            }
        }
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    
    }
};
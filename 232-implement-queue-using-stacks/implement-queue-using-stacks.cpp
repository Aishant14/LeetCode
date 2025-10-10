class MyQueue {
public:
    stack <int> inp;
    stack <int> op;
    int peek1 = INT_MIN;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(inp.empty()){
            peek1 = x;
        }
           inp.push(x);
    }
    
    int pop() {
        if(op.empty()){
            while(!inp.empty()){
                op.push(inp.top());
                inp.pop();
            }
        }
        int temp = op.top();
            op.pop();
            return temp;
    }
    
    int peek(){
        if(op.empty()){
            return peek1;
        }
        else{
            return op.top();
        }
    }
    
    bool empty() {
        if(op.empty() && inp.empty()){
            return true;
        }
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
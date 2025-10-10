class MyQueue {
public:
    stack<int> prime;
    stack <int> sec;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(prime.empty()){
            prime.push(x);
        }
        else{
            while(!prime.empty()){
                int temp = prime.top();
                sec.push(temp);
                prime.pop();
            }
            prime.push(x);
            while(!sec.empty()){
                prime.push(sec.top());
                sec.pop();
            }
        }
    }
    
    int pop() {
        int res = prime.top();
        prime.pop();
        return res;
    }
    
    int peek() {
        return prime.top();
    }
    
    bool empty() {
        if(prime.empty()) return true;
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
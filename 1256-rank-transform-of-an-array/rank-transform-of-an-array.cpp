class node{
        public:
        int val;
        int pos;

        node(int val, int pos){
            this->val = val;
            this->pos = pos;
        }
};
struct mycomp{
    bool operator()(node&n1, node&n2){
        return n1.val > n2.val;
    }
};

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<node,vector<node>,mycomp> pq;
        for(int i =0; i<arr.size(); i++){
            node n1(arr[i],i);
            pq.push(n1);
        }
        int rank = 0;
        int prev = INT_MIN;
        while(!pq.empty()){
            node curr = pq.top();
            if(prev != curr.val){
                arr[curr.pos] = ++rank;
                prev = curr.val;
            }
            else{
                arr[curr.pos] = rank;
            }
            pq.pop();
        }
        return arr;
    }
};
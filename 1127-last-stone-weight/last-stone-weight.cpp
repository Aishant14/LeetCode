class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i : stones){
            pq.push(i);
        }
        while(pq.size() > 1){
            int larg = pq.top();
            pq.pop();
            int seclarg = pq.top();
            pq.pop();
            int res = larg - seclarg;
            if(res != 0) {
                pq.push(res);
            }
        }
        if(pq.empty())  return false;
        else return pq.top();
    }
};
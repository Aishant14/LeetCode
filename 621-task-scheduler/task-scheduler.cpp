class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int fres = 0;
        unordered_map<char,int> mp;
        for(char i : tasks){
            mp[i]++;
        }
        priority_queue<int> pq;
        for(auto pair: mp){
            pq.push(pair.second);
        }
        while(!pq.empty()){
            vector<int> temp;
            for(int i =1; i<= n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(int i : temp){
                if(i >0){
                pq.push(i);
                }
            }
            if(!pq.empty()){
                fres += n+1;
            }
            else{
                fres += temp.size();
            }
        }
        return fres;
    }
};
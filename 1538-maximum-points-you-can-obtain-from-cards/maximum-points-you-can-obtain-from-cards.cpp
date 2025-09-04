class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum =0, rsum =0;
        int left = k-1;
        while(left >= 0){
            lsum += cardPoints[left];
            left--;
        }
        int maxS = lsum;
        int rightp = cardPoints.size() -1;
        for(int i = k-1; i>= 0;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rightp--];
            maxS = max(maxS,lsum+rsum);
        }
        return maxS;
    }
};
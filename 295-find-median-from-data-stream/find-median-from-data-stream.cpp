class MedianFinder {
public:
    priority_queue<int> leftmax;
    priority_queue<int,vector<int>,greater<int>> rightmin;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftmax.empty() || num <= leftmax.top()){
            leftmax.push(num);
        }
        else{
            rightmin.push(num);
        }

        // always maintain left size greater than right size by 1 difference
        if(leftmax.size()  > rightmin.size() +1) {
            rightmin.push(leftmax.top());
            leftmax.pop();
        }
        else if (rightmin.size() > leftmax.size() ){
            leftmax.push(rightmin.top());
            rightmin.pop();
        }
    }
    
    double findMedian() {
        if(leftmax.size() == rightmin.size()){
            return ((double)leftmax.top() + (double)rightmin.top()) / 2.0;
        }
        else{
            return (double)leftmax.top();
        }
    }
};   

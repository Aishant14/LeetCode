class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int size = dimensions.size();
        int rectn0 = -1;
        int MaxArea = -1;
        double maxDig = -1;
        for(int i =0; i< size; i++){
            int len = dimensions[i][0];
            int bred = dimensions[i][1];
            double Dig = sqrt((len*len) + (bred*bred));
            if(Dig == maxDig){
                int area = len*bred;
                if(area > MaxArea)
                {
                    MaxArea = area;
                }
            }
            if(Dig > maxDig){
                maxDig = Dig;
                int area = len*bred;
                MaxArea = area;
            }
        }
        return MaxArea;
    }
};
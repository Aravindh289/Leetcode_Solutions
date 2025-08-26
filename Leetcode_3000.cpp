class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int r = dimensions.size();
        double max_d = -1.0;
        int max_area = -1;
        for(int i=0;i<r;i++)
        {
            double a = (dimensions[i][0] * dimensions[i][0]) + (dimensions[i][1] * dimensions [i][1]);  
            int area = dimensions[i][0] * dimensions[i][1];
            a = sqrt(a);
            if(a > max_d)
            {
                max_d = a;
                max_area = area;
            }
            else if(a == max_d)
            {
                max_area = max(area,max_area);
            }
        }
        return max_area;
    }
};
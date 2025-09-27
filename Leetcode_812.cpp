class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double max_area = INT_MIN;
        int n = points.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    double x1,y1,x2,y2,x3,y3;
                    x1 = points[i][0] , y1 = points[i][1];
                    x2 = points[j][0] , y2 = points[j][1];
                    x3 = points[k][0] , y3 = points[k][1];
                    double area = 0.5 * fabs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
                    max_area = max(area,max_area);
                }
            }
        }
        return max_area;
    }
};
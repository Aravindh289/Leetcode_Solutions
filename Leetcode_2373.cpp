class Solution {
public:
    int mm(vector<vector<int>>& grid,int rs,int re,int cs,int ce)
    {
        int maxx = 0;
        for(int i=rs;i<=re;i++)
        {
            for(int j=cs;j<=ce;j++)
            {
                maxx = max(maxx,grid[i][j]);
            }
        }
        return maxx;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> v(r-2,vector<int>(c-2,0));
        for(int i=0;i<r-2;i++)
        {
            for(int j=0;j<c-2;j++)
            {
                int val = mm(grid,i,i+2,j,j+2);
                v[i][j] = val;
            }
        }
        return v;
    }
};
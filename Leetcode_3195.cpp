class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int l = col, r = -1, up = row, down = -1;
        for (int i = 0; i < row; i++) 
        {
            for (int j = 0; j < col; j++) 
            {
                if (grid[i][j] == 1)
                {
                    l = min(l, j);
                    r = max(r, j);
                    up = min(up, i);
                    down = max(down, i);
                }
            }
        }
        
        if (r == -1) 
            return 0;

        return (r - l + 1) * (down - up + 1);
    }
};

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) 
    {
        //upper part without including diagonal(asc)
        upper_diagonal(grid);
        //lower part including diagonal(desc)
        lower_diagonal(grid);
        return grid;
    }
    void upper_diagonal(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        int j = r-1,i=0;
        while(j>0)
        {
            vector<int> v = {};
            i = 0;
            int cpyj = j;
            int pai = i,paj = j;
            while(i<c)
            {
               v.push_back(grid[i][cpyj]);
               i = ((i+1) < c)?i+1:-1;
               cpyj = ((cpyj+1) < r)?cpyj+1:-1;
               if(i == -1 || cpyj == -1)
               {
                  break;
               }
            }
            sort(v.begin(),v.end());
            int tta = 0;
            int n = v.size();
            while(pai<c)
            {
                grid[pai][paj] = v[tta];
                tta = ((tta+1) < n)?tta+1:-1;
                if(tta == -1) break;
                pai++;
                paj++;
            }
            j--;
        }
    }
    void lower_diagonal(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        int i = 0,j = 0;
        while(i < r)
        {
            int cpyi = i;
            vector<int> v = {};
            j = 0;
            int pai=i,paj=j;
            while(j<c)
            {
               v.push_back(grid[cpyi][j]);
               cpyi = (cpyi+1 < c)?cpyi+1:-1;
               j = (j+1 < c)?j+1:-1;
               if(j == -1 || cpyi == -1)
                  break;     
            }
            sort(v.begin(),v.end(),greater<int>());
            int n = v.size();
            int tta = 0;
            while(paj<c)
            {
                grid[pai][paj] = v[tta];
                tta = ((tta+1) < n)?tta+1:-1;
                if(tta == -1) break;
                pai++;
                paj++;
            }
            i++;
        }
    }
};
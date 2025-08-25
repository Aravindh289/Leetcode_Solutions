class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int r = mat.size(),c = mat[0].size();
        vector<int> v;
        for(int d=0;d<(r+c)-1;d++)
        {
            //bottom - up
            if(d%2==0)
            {
               int i = min(d, r - 1);
               int j = d - i;
               while(i<r && i>=0 && j<c && j>=0)
               {
                  v.push_back(mat[i][j]);
                  i--;
                  j++;
               }
            }
            //top - down
            else
            {
                int j = min(d, c - 1);
                int i = d - j;
                while(i<r && i>=0 && j<c && j>=0)
                {
                    v.push_back(mat[i][j]);
                    i++;
                    j--;
                }
            }
        }
        return v;
    }
};
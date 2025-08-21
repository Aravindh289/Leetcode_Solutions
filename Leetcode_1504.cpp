class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 1) 
                {
                    if(i>0)
                        dp[i][j] = dp[i-1][j] + 1;
                    else
                        dp[i][j] = 1;
                } 
                else 
                {
                    dp[i][j] = 0;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int minHeight = INT_MAX;
                for (int k = j; k >= 0; k--) {
                    if (dp[i][k] == 0) 
                        break; 
                    minHeight = min(minHeight, dp[i][k]);
                    ans += minHeight;
                }
            }
        }
        return ans;
    }
};

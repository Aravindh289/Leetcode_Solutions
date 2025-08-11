class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int MOD = 1e9 + 7;
        vector<int> v,rtn;
        for (int i = 0; i < 31; i++) 
        {
            if (n & (1 << i)) 
            {
                v.push_back(1 << i);
            }
        } 
        for(int i=0;i<queries.size();i++)
        {
            int st = queries[i][0],end = queries[i][1];
            long long prod = 1;
            for(int j=st;j<=end;j++)
            {
               prod = (prod*v[j]) % MOD;
            }
            rtn.push_back(prod);
        }
        return rtn;
    }
};
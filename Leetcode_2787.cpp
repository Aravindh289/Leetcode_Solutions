class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;
        vector<int> dp(n+1,0),powers;
        for (int base = 1; ; base++) 
        {
            long long p = (long long)(pow(base, x) + 0.5); 
            if (p > n) break;
            powers.push_back((int)p);
        }
        dp[0] = 1;
        int  p = powers.size();
        for(int i=0;i<p;i++)
        {
            int a = powers[i];
            for(int i=n;i>=a;i--)
            {
                dp[i] = (dp[i] + dp[i-a]) % MOD;
            }
        }
        return dp[n];

    }
};
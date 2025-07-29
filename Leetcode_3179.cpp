class Solution {
public:
    using ll = long long;
    int mod = 1e9+7;
    vector<int> calc(vector<int> v)
    {
        int n = v.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
           sum = (sum+v[i]) % mod;
           v[i]=sum;
        }
        return v;
    }
    int valueAfterKSeconds(int n, int k) {
        vector<int> v(n,1);
        while(k>0)
        {
           v = calc(v);
           k--;
        }
        return v[n-1];
    }
};

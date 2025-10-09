class Solution {
public:
    vector<int> compute(int n)
    {
        vector<int> v(n,1);
        v[0] = 0;
        v[1] = 0;
        for(int i=2;i<sqrt(n);i++)
        {
            if(v[i])
            {
                for(int j=i*i;j<n;j+=i)
                {
                    v[j] = 0;
                }
            }
        }
        return v;
    }
    int countPrimes(int n)
    {
        int c = 0;
        if(n<2) return c;
        vector<int> rslt = compute(n);
        for(auto a:rslt)
            if(a) c++;
        return c;
    }
};
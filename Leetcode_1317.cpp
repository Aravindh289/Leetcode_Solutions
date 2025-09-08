class Solution {
public:
    bool c_z(int a)
    {
        while(a!=0)
        {
            int d = a%10;
            if(d == 0) return false;
            a/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) 
    { 
        int i = 1;
        while(1)
        {
            int r = n - i;
            if(i + r == n)
            {
                if(c_z(r) && c_z(i))
                {
                    return {r , i};
                }
            }
            i++;
        }  
    }
};
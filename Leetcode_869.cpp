class Solution {
public:
    string sortnmbr(int x)
    {
        string a = to_string(x);
        sort(a.begin(),a.end());
        return a;
    }
    bool reorderedPowerOf2(int n) {
        string trgt = to_string(n);
        sort(trgt.begin(),trgt.end());
        for(int i=0;i<=30;i++)
        {
            int a = 1 << i; //calc 2 power n value 
            string x = sortnmbr(a);
            if(x == trgt)
            {
                return true;
            }
        }
        return false;
    }
};
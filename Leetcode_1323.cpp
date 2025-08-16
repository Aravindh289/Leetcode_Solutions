class Solution {
public:
    int maximum69Number (int num) 
    {
        string s = to_string(num);
        int i=0,n = s.size();
        while(i < n)
        {
            if(s[i] == '6')
            {
              s[i] = '9';
              break;
            }
            i++;
        }
        long long l = stoll(s);
        return int(l);
    }
};
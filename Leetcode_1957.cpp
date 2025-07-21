class Solution {
public:
    string makeFancyString(string s) {
        int same = 1;
        int i=1;
        while(i < s.size())
        {
            if(s[i]==s[i-1])
            {
                same++;
                if(same==3)
                {
                    s.erase(i,1);
                    same--;
                    continue;
                }
            }
            else
            {
                same=1;
            }
            i++;
        }
        if(same==3)
        {
            s.erase(i,1);
        }
        return s;
    }
};

//the above code is the solution to the problem based on brute force and it i'll TLE for large inputs because itz time complexity is O(n^2)
//so we optimised the approach

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        int i=1;
        string rslt = "";
        rslt+=s[0];
        int c=1;
        for(i=1;i<n;i++)
        {
           if(s[i]==s[i-1])
           {
              c++;
           }
           else
           {
              c=1;
           }
           if(c<3)
           {
            rslt+=s[i];
           }
        }
        return rslt;
    }
};
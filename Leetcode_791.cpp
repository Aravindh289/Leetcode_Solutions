class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> m1;
        map<int,char> m2;
        int i = 0;
        for(auto a:order)
        {
            i++;
            m1[a] = i;
        }
        for(auto a:m1)
        {
            m2[a.second] = a.first;
        }
        vector<int> v;
        for(auto a:s)
        {
            if(m1.find(a)!=m1.end())
                v.push_back(m1[a]);
        }
        sort(v.begin(),v.end());
        string rtn,rtn1;
        for(auto a:v)
        {
            rtn += m2[a];
        }
        int n = v.size();
        for(auto a:s)
        {
            if(rtn.find(a)==string::npos)    
                rtn1+=a;
        }
        sort(rtn1.begin(),rtn1.end());
        return rtn+rtn1;
    }
};
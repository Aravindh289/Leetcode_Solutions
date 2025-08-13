class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> m;
        for(auto a:arr)
        {
            if(a<0)
            {
               m[((a%k)+k)%k]++;
            }
            else
            {
                m[a%k]++;
            }
        }
        int c=0;
        for(auto i=m.begin();i!=m.end();i++)
        {
            int key = i->first;
            int val = i->second;
            if(key == 0)
            {
                if(val%2!=0)
                {
                    return false;
                }
            }
            else
            {
                int b = k - key;
                if (m.find(b) == m.end()) return false;
                if (m[b] != val) return false;
            }
        }
        return true;
    }
};
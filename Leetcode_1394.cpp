class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> m;
        for(int i=0;i<arr.size();i+=1)
        {
            m[arr[i]]+=1;
        }
        int lucky=-1;
        for(auto a:m)
        {
            if(a.first == a.second)
            {
                lucky = a.first;
            }
        }
        return lucky;
    }
};
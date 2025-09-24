class Solution {
public:
    int findtopxfreq(map<int,int>& mm,int x)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto a:mm)
        {
            pq.push({a.second,a.first});
            if(pq.size() > x) pq.pop();
        }
        int sum = 0;
        while(pq.size()>0)
        {
            auto a = pq.top();
            sum += a.first*a.second;
            pq.pop();
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int rs = n - k + 1;
        int i = 0;
        vector<int> v;
        while(i<rs)
        {
            map<int,int> mm = {};
            for(int j=i;j<(i+k) && j<n;j++)
            {
                mm[nums[j]]++;
            }
            i++;
            int result = findtopxfreq(mm,x);     
            v.push_back(result);       
        }
        return v;
    }
};
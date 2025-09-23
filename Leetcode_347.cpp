class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> m;
        vector<int> v;
        for(auto a:nums) m[a]++;
        for(auto a:m)
        {
            pq.push({a.second,a.first});
            if(pq.size() > k) pq.pop();
        }
        while(pq.size()>0)
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};


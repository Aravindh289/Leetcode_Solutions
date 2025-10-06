class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //priority_queue<int,vector<int>,greater<int>> pq;
        priority_queue<pair<int,int>> pq;
        int n = points.size();
        vector<int> idx;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            auto a = pow(x1,2) + pow(y1,2);
            pq.push({a,i});          
            if(pq.size() > k) 
            {
                pq.pop();
            }
        }
        while(pq.size() > 0)
        {
            pair<int,int> p = pq.top();
            ans.push_back(points[p.second]);
            pq.pop();
        }
        return ans;
    }
};
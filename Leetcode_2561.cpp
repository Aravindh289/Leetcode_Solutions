class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> m, b1, b2;
        vector<int> left, right;
        long long swap = 0;
        int mini = INT_MAX;

        for (int i = 0; i < basket1.size(); i++) 
        {
            b1[basket1[i]]++;
            m[basket1[i]]++;
            mini = min(mini, basket1[i]);

            b2[basket2[i]]++;
            m[basket2[i]]++;
            mini = min(mini, basket2[i]);
        }

        for (auto x : m) 
        {
            if (x.second % 2 != 0)
                return -1;
        }

        for (auto x : m) 
        {
            int val = x.first;
            int total = x.second / 2;
            int extra1 = b1[val] - total;
            int extra2 = b2[val] - total;

            for (int i = 0; i < extra1; i++) 
                left.push_back(val);
            for (int i = 0; i < extra2; i++) 
                right.push_back(val);
        }

        sort(left.begin(), left.end());
        sort(right.rbegin(), right.rend());

        for (int i = 0; i < left.size(); i++) 
        {
            int cost = min(left[i], right[i]);
            swap += min(cost, 2 * mini);
        }

        return swap;
    }
};

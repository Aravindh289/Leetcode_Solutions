//INTERSECTION OF TWO ARRAYS - 1
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int n=nums1.size(),m=nums2.size();
        unordered_map<int,int> m1;
        for(int i=0;i<n;i++)
        {
            m1[nums1[i]]++;
        }
        unordered_set<int> s;
        for(int i=0;i<m;i++)
        {
            if(m1.count(nums2[i]))
            {
                s.insert(nums2[i]);
            }
        }
        for(auto a:s)
        {
            v.push_back(a);
        }
        return v;
    }
};
//INTERSECTION OF TWO ARRAYS - 2
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1, m2;
        vector<int> result;

        for (int num : nums1) {
            m1[num]++;
        }
        for (int num : nums2) {
            m2[num]++;
        }

        for (auto& [num, freq1] : m1) {
            if (m2.count(num)) {
                int times = min(freq1, m2[num]);
                for (int i = 0; i < times; ++i) {
                    result.push_back(num);
                }
            }
        }
        return result;
    }
};

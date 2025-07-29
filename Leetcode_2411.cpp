class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int orr = 0;
            int maxor = 0;

            for (int k = i; k < n; k++) {
                maxor = maxor | nums[k];
            }

            for (int j = i; j < n; j++) {
                orr = orr | nums[j];
                if (orr == maxor) {
                    v.push_back(j - i + 1);
                    break;
                }
            }
        }

        return v;
    }
};

//the brute force approach ill reach the TLE so optimising it
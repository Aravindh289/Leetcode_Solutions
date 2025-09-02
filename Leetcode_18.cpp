class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;  
            int val1 = nums[i]; 
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue; 
                int val2 = nums[j];

                int l = j + 1, r = n - 1;
                while (l < r) {
                    int sum = val1 + val2 + nums[l] + nums[r];

                    if (sum == target) {
                        v.push_back({(int)val1, (int)val2, nums[l], nums[r]});

                        while (l < r && nums[l] == nums[l+1]) l++; 
                        while (l < r && nums[r] == nums[r-1]) r--; 
                        l++;
                        r--;
                    } 
                    else if (sum > target) {
                        r--;
                    } 
                    else {
                        l++;
                    }
                }
            }
        }
        return v;
    }
};

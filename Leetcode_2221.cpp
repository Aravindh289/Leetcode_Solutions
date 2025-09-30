class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums[0];
        vector<int> lvl(nums.begin(), nums.end());
        while (lvl.size() > 1) 
        {
            vector<int> cpy(lvl.begin(), lvl.end());
            int n = cpy.size();
            lvl.clear();
            for (int i = 0; i < n - 1; i++)
                lvl.push_back(0);
            for (int i = 0; i < n - 1; i++) 
            {
                lvl[i] = (cpy[i] + cpy[i + 1]) % 10;
            }
        }
        return lvl[0];
    }
};
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1;) {
            if (nums[i] == nums[i + 1]) {
                nums.erase(nums.begin() + i);
            } else {
                i++;
            }
        }

        int hill = 0, valley = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) 
                hill++;
            else if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1])
                valley++;
        }
        return hill + valley;
    }
};

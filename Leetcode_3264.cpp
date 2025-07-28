class Solution {
public:
    int mini(vector<int>& nums)
    {
        int m=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] < nums[m])
            {
                m=i;
            }
        }
        return m;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k>0)
        {
           int update = mini(nums);
           nums[update] = nums[update] * multiplier;
           k--;
        }
        return nums;
    }
};
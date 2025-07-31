class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n= size(nums);       
        for (int i = 0; i < n; i++) 
        {
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) 
            {
                swap(nums[i], nums[nums[i] - 1]); 
            }
        }
        int small=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==small)
            {
               small++;
            }
        }
        return small;
    }
};
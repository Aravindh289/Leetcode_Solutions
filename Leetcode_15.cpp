class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> v;
        for(int i=0;i<n;i++)
        {
            int l = i+1;
            int r = n-1;
            int val = nums[i];
            int trgt = 0;
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            while(l<r)
            {
                int sum = val + nums[l] + nums[r];
                if(sum == trgt)
                {
                    vector<int> tsum = {val,nums[l],nums[r]};
                    v.insert(tsum);
                    // while (l < r && nums[l] == nums[l + 1]) l++;
                    // while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }
                else if(sum < trgt)
                    l++;
                else 
                    r--;
            }
        }
        return vector<vector<int>>(v.begin(),v.end());
    }
};

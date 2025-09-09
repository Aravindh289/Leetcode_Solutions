class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int cz = 0,max_c1 = INT_MIN;
        int l=0,r=0;
        while(r<n)
        {
            if(nums[r] == 0)
            {
                cz++;
            }
            if(cz>k)
            {
                if(nums[l] == 0)
                {
                    cz--;
                }
                l++;
            }
            max_c1=max(max_c1,r-l+1);
            r++;
        }
        return max_c1;
    }
};

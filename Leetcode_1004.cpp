class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0,r = 0;
        int n = nums.size();
        int max_len = INT_MIN;
        int len = 0;
        while(r<n)
        {
           if(nums[r] == 1)
           {
              len = (r-l)+1;
              r++;
           }
           else if(nums[r] == 0 && k>0)
           {
              k--;
              len = (r-l)+1;
              r++;
           }
           else
           {
              while (nums[l] == 1) l++;
              l++; 
              k++;
              len = (r-l)+1;
           }
           max_len = max(max_len,len);
        }
        return max_len;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        bool del = false;
        for(int i=0;i<n;i++)
        {
            int cc = 0;
            int bp = 0;
            for(int j=i;j<n;j++)
            {
                if(nums[j] == 0 && bp<1)
                {
                    bp += 1;
                    del = true;
                }
                else if(nums[j] == 1)
                {
                    cc++;
                }
                else
                {
                    break;
                }
            }
            c = max(c,cc);
        }
        if(!del)
          return n-1;
        return c;
    }
};
//it is the brute for approach and it ill reach TLE so optimised code
//so the optimised 2 pointer approach
class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        int zero = -1;
        int st = 0,max_len = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
            {
                st = zero + 1;
                zero = i;
            }
            max_len = max(max_len,i-st);
        }
        return max_len;
    }
};
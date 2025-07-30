class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cand,maxand=0;
        int maxlen=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            cand = nums[i];
            int len = 1;
            if (cand > maxand) {
                maxand = cand;
                maxlen = len;
            } 
            else if (cand == maxand) 
            {
                maxlen = max(maxlen, len);
            }
            for(int j=i+1;j<n;j++)
            {
                cand &= nums[j];
                len++;
                if(cand > maxand)
                {
                    maxand = max(cand,maxand);
                    maxlen = len;
                }
                else if(cand == maxand)
                {
                    maxlen = max(len,maxlen);
                }
                if(cand == 0)
                {
                    break;
                }
            }
        }
        return maxlen;
    }
};
//the brute force approach ill lead to TLE So optimising it...
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxlen = 0;
        int maxx = 0;
        for(int i=0;i<nums.size();i++)
        {
            maxx=max(maxx,nums[i]);
        }
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == maxx)
            {
                c++;
                maxlen = max(c,maxlen);
            }
            else
            {
                c=0;
            }
        }
        return maxlen;
    }
};
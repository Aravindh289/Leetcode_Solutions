class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int grp=1,st=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]-st>k)
            {
              st=nums[i];
              grp+=1;
            }
        }
        return grp;
    }
};
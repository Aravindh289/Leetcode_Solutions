class Solution {
public:
    bool iszf(vector<int>& nums,int st,int end)
    {
        for(int i=st;i<=end;i++)
        {
            if(nums[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        long long c = 0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                if(iszf(nums,i,j))
                   c++;
            }
        }
        return c;
    }
};
//the brute force i'll lead to TLE so optimal approach
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long c = 0,cz = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
               cz++;
            else
               cz=0;
            c+=cz;
        }
        return c;
    }
}; 
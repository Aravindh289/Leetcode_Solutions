class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd=0,even=0,alt=1;
        int prev=nums[0];
        prev%2==0?even+=1:odd+=1;
        for(int i=1;i<nums.size();i+=1)
        {
            if(nums[i]%2!=prev%2)
                alt+=1;
            if(nums[i]%2==0)
                even++;
            if(nums[i]%2!=0)
                odd++;
            prev = nums[i];
        }
        return max(alt,max(odd,even));
    }
};
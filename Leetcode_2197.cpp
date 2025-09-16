class Solution {
public:
    int gcd(int a, int b) 
    {
        while(b != 0) 
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int i=0;
        while(i<nums.size()-1)
        {
            int rgcd = gcd(nums[i],nums[i+1]);
            if(rgcd > 1)
            {
                nums[i] = (1LL*nums[i]*nums[i+1])/rgcd;
                nums.erase(nums.begin() + (i+1));
                if(i>0)  
                    i--;
            }
            else
            {
                i++;
            }
        }
        return nums;
    }
};
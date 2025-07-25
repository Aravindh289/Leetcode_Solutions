class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool posi = false;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                posi=true;
                break;
            }
        }
        int sum=0;
        if(posi)
        {
            auto it = nums.begin();
            while (it != nums.end()) 
            {
                if (*it < 1)
                    it = nums.erase(it);  
                else
                    ++it;
            }
            set<int> s;
            for(int i=0;i<nums.size();i++)
            {
                s.insert(nums[i]);
            }
            for(auto a:s)
            {
                sum+=a;
            }
            return sum;
        }
        else
        {
            int min=nums[0];
            for(int i=1;i<nums.size();i++)
            {
                if(nums[i]>min)
                {
                    min = nums[i];
                }
            }
            return min;
        }
        return sum;        
    }
};
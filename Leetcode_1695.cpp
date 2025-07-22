class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> m;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            if(m[nums[i]] > 1)
            {
                sum-=nums[i];
                m[nums[i]]--;
            }
            sum+=nums[i];
        }
        return sum;
    }
};

//the above brute approach ill lead to the TLE so after optimising the code we can use the sliding window approach to solve this problem

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int r=0,l=0,sum=0,max_sum=0;
        unordered_set<int> s;
        while(r<nums.size())
        {
            if(s.count(nums[r]))
            {
                sum-=nums[l];                
                s.erase(nums[l]);
                l+=1;
            }
            else
            {
                s.insert(nums[r]);
                sum+=nums[r];
                max_sum=max(sum,max_sum);
                r++;
            }
        }
        return max_sum;
    }
};
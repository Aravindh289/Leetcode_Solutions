class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int p = 0,mp = 0;;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    int a = nums[i],b = nums[j],c = nums[k];
                    if(a+b>c && b+c>a && c+a>b)
                    {
                        p = a+b+c;
                    }
                    mp = max(p,mp);
                }
            }
        }
        return mp;
    }
};
//the brute for will lead to TLE So
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();        
        if(n<3) return 0;
        for(int i = n-1;i>=2;i--)
        {
            int a = nums[i],b = nums[i-1],c = nums[i-2];
            if(a+b>c && b+c>a && c+a>b)
                return a+b+c;
        }
        return 0;
    }
};
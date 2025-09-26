class Solution {
public:
    bool isvalid(int a,int b,int c)
    {
        if(a+b > c && b+c > a && c+a > b)
            return true;
        return false;
    }
    int triangleNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int c = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i!=j)
                {
                    for(int k=j+1;k<n;k++)
                    {
                        if(i!=k && j!=k)
                        {
                            if(isvalid(nums[i],nums[j],nums[k])) 
                                c++;
                        }
                    }
                }
            }
        }   
        return c;
    }
};
//the above brute force will lead to TLE So optimised three pointer approach
class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int k = nums.size()-1;
        int count = 0;
        while(k>1)
        {
           int c = nums[k];
           int j = k-1;
           int i = 0;
           while(i!=j)
           {
                int a = nums[i];
                int b = nums[j];
                if(a+b > c && b+c > a && c+a > b)
                {
                    count += (j-i);
                    j--;
                }
                else
                    i++;
           }
           k--;
        }
        return count;
    }
}; 
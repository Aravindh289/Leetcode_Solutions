class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,n=height.size();
        int max_amt = INT_MIN;
        while(j > i)
        {
           int capacity = (j-i) * min(height[i],height[j]);
           max_amt = max(max_amt,capacity);
           if(height[i] > height[j])
           {
             j--;
           }
           else
           {
             i++;
           }
        }
        return max_amt;
    }
};
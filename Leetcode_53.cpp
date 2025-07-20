class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int m_sum = nums[0];         
        for (int r = 0; r < n; r++) {        
            sum += nums[r];    
            m_sum = max(sum, m_sum);
            if (sum < 0) {
                sum = 0; 
            }
        }
        return m_sum;
    }
};

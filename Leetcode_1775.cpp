class Solution {
public:
    int sol(vector<int>& nums1, vector<int>& nums2, int s1, int s2) 
    {
        int l1 = nums1.size() * 1;
        int r1 = nums1.size() * 6;
        int l2 = nums2.size() * 1;
        int r2 = nums2.size() * 6;

        if (r1 < l2 || r2 < l1) return -1; 

        int i = nums1.size() - 1, j = 0;
        int nop = 0;
        while (s1 > s2 && (i >= 0 || j < nums2.size())) {
            int change1 = (i >= 0 ? nums1[i] - 1 : 0);
            int change2 = (j < nums2.size() ? 6 - nums2[j] : 0);

            if (change1 >= change2) {
                s1 -= change1;
                i--;
            } else {
                s2 += change2;
                j++;
            }
            nop++;
        }
        return (s1 <= s2 ? nop : -1);
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int sum1 = 0,sum2 = 0;
        int n = nums1.size(),m = nums2.size();
        for(auto a:nums1)
            sum1+=a;
        for(auto a:nums2)
            sum2+=a;
        
        if(sum1 == sum2)
           return 0;
        if(sum1 > sum2)
            return sol(nums1,nums2,sum1,sum2);
        else
            return sol(nums2,nums1,sum2,sum1);
    }
};
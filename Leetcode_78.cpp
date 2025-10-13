class Solution {
private:
    vector<vector<int>> v;
public:
    void form(int idx,vector<int> &nums,vector<int> &tmp)
    {
        if(idx == nums.size())
        {
            v.push_back(tmp);
            return ;
        }
        tmp.push_back(nums[idx]);
        form(idx+1,nums,tmp);
        tmp.pop_back();
        form(idx+1,nums,tmp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        int idx = 0;
        form(idx,nums,temp);
        return v;
    }
};
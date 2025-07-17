class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int last = digits[digits.size()-1];
        if (last < 9)
        {
            digits[digits.size()-1] = last + 1;
            return digits;
        }
        int carry = 1;
        deque<int> d;
        for(int i=digits.size()-1;i>=0;i--)
        {
            int sum = digits[i]+carry;
            d.push_front(sum%10);
            carry = sum /10;
        }
        if(carry)
        {
            d.push_front(carry);
        }
        return vector<int>(d.begin(), d.end());
    }
};

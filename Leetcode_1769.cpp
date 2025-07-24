class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int l=0,r=0;
        vector<int> rslt;
        while(l<n)
        {
            int distance = 0;
            for(int r=0;r<n;r++)
            {
                if(boxes[r]=='1')
                { 
                    distance+=abs(l-r);
                }
            }
            rslt.push_back(distance);
            l++;
        }
        return rslt;
    }
};
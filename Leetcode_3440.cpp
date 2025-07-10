class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> gaps;
        gaps.push_back(startTime[0]); 

        for (int i = 1; i < n; i++) 
        {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }

        gaps.push_back(eventTime - endTime[n - 1]); 

        vector<int> maxLeft(n + 1);
        vector<int> maxRight(n + 1);

        maxLeft[0] = gaps[0];
        for (int i = 1; i <= n; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], gaps[i]);
        }

        maxRight[n] = gaps[n];
        for (int i = n - 1; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], gaps[i]);
        }

        int maxTime = 0;

        for (int i = 0; i < n; ++i) {
            int dur = endTime[i] - startTime[i];

            int leftGap = gaps[i];
            int rightGap = gaps[i + 1];

            int leftMax = (i > 0) ? maxLeft[i - 1] : 0;
            int rightMax = (i + 2 <= n) ? maxRight[i + 2] : 0;

            bool canMove = dur <= max(leftMax, rightMax);

            int totalFreeTime = leftGap + rightGap + (canMove ? dur : 0);
            maxTime = max(maxTime, totalFreeTime);
        }

        return maxTime;
    }
};
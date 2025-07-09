class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps;

        gaps.push_back(startTime[0] > 0 ? startTime[0] : 0);

        for (int i = 0; i < n - 1; ++i) {
            gaps.push_back(startTime[i + 1] - endTime[i]);
        }

        if (eventTime > endTime[n - 1]) {
            gaps.push_back(eventTime - endTime[n - 1]);
        }

        if (gaps.size() < k + 1) {
            return accumulate(gaps.begin(), gaps.end(), 0);
        }

        int sum = 0;
        for (int i = 0; i <= k; ++i) {
            sum += gaps[i];
        }

        int max_gaps = sum;

        for (int i = k + 1, j = 0; i < gaps.size(); ++i, ++j) {
            sum = sum - gaps[j] + gaps[i];
            max_gaps = max(max_gaps, sum);
        }

        return max_gaps;
    }
};

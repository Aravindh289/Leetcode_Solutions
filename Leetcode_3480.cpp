class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> subarrays;
        vector<int> arr;
        for (int i = 1; i <= n; i++) 
            arr.push_back(i);

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = i; j < n; j++) {
                temp.push_back(arr[j]);
                subarrays.push_back(temp);
            }
        }

        int total = subarrays.size(); 
        int maxValid = 0;

        for (int removeIndex = 0; removeIndex < conflictingPairs.size(); removeIndex++) {
            vector<pair<int, int>> conflicts;
            for (int i = 0; i < conflictingPairs.size(); i++) {
                if (i != removeIndex) {
                    conflicts.push_back({conflictingPairs[i][0], conflictingPairs[i][1]});
                }
            }

            int invalid = 0;
            for (auto &sub : subarrays) 
            {
                for (auto &[a, b] : conflicts) 
                {
                    bool hasA = false, hasB = false;
                    for (int num : sub) {
                        if (num == a) hasA = true;
                        if (num == b) hasB = true;
                    }
                    if (hasA && hasB) 
                    {
                        invalid++;
                        break; 
                    }
                }
            }
            maxValid = max(maxValid, total - invalid);
        }
        return maxValid;
    }
};

// the above code ill follow the brute force method so it ill lead to TLE 
class FindSumPairs {
public:
    vector<int> n1, n2;
    unordered_map<int, int> freq;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (int num : n2) {
            freq[num]++;
        }
    }

    void add(int index, int val) {
        freq[n2[index]]--;
        n2[index] += val;
        freq[n2[index]]++;
    }

    int count(int tot) {
        int c = 0;
        for (int x : n1) {
            int required = tot - x;
            if (freq.count(required)) {
                c += freq[required];
            }
        }
        return c;
    }
};

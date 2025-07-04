class Solution {
public:
    char nextChar(char c) {
        return c == 'z' ? 'a' : c + 1;
    }

    char findKthCharacter(int opIndex, long long k, vector<int>& operations, vector<long long>& lengths) {
        if (opIndex < 0)
            return 'a';

        long long half = lengths[opIndex] / 2;
        int op = operations[opIndex];

        if (k < half) {
            return findKthCharacter(opIndex - 1, k, operations, lengths);
        } else {
            char c = findKthCharacter(opIndex - 1, k - half, operations, lengths);
            return (op == 0 ? c : nextChar(c));
        }
    }

    char kthCharacter(long long k, vector<int>& operations) {
        long long len = 1;
        int n = operations.size();
        vector<long long> lengths;

        for (int i = 0; i < n; ++i) {
            len *= 2;
            lengths.push_back(len);
            if (len > k) break;
        }

        return findKthCharacter(lengths.size() - 1, k - 1, operations, lengths);
    }
};

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int msum = 0;
        if (y > x) {
            stack<char> ss;
            ss.push(s[0]); 
            int i = 1;

            while (i < s.size()) {
                if (!ss.empty() && ss.top() == 'b' && s[i] == 'a') {
                    ss.pop();
                    s.erase(i - 1, 2);
                    msum += y;
                    i = max(0, i - 2);
                    if (i < s.size()) {
                        ss = stack<char>();
                        if (i >= 0) ss.push(s[i]);
                        i++;
                    }
                } else {
                    ss.push(s[i]);
                    i++;
                }
            }

            stack<char> a;
            if (!s.empty()) a.push(s[0]);
            int j = 1;

            while (j < s.size()) {
                if (!a.empty() && a.top() == 'a' && s[j] == 'b') {
                    a.pop();
                    s.erase(j - 1, 2);
                    msum += x;
                    j = max(0, j - 2);
                    if (j < s.size()) {
                        a = stack<char>();
                        if (j >= 0) a.push(s[j]);
                        j++;
                    }
                } else {
                    a.push(s[j]);
                    j++;
                }
            }

        } else {
            stack<char> a;
            if (!s.empty()) a.push(s[0]);
            int j = 1;

            while (j < s.size()) {
                if (!a.empty() && a.top() == 'a' && s[j] == 'b') {
                    a.pop();
                    s.erase(j - 1, 2);
                    msum += x;
                    j = max(0, j - 2);
                    if (j < s.size()) {
                        a = stack<char>();
                        if (j >= 0) a.push(s[j]);
                        j++;
                    }
                } else {
                    a.push(s[j]);
                    j++;
                }
            }

            stack<char> ss;
            if (!s.empty()) ss.push(s[0]);
            int i = 1;

            while (i < s.size()) {
                if (!ss.empty() && ss.top() == 'b' && s[i] == 'a') {
                    ss.pop();
                    s.erase(i - 1, 2);
                    msum += y;
                    i = max(0, i - 2);
                    if (i < s.size()) {
                        ss = stack<char>();
                        if (i >= 0) ss.push(s[i]);
                        i++;
                    }
                } else {
                    ss.push(s[i]);
                    i++;
                }
            }
        }
        return msum;
    }
};

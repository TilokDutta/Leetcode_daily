class Solution {
public:
    bool isPal(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void helper(const string& s, int idx, string& s1, string& s2, int& res) {
        if (idx == s.length()) {
            if (isPal(s1, 0, s1.length() - 1) && isPal(s2, 0, s2.length() - 1)) {
                res = max(res, (int)(s1.length() * s2.length()));
            }
            return;
        }

        // Include s[idx] in s1
        s1.push_back(s[idx]);
        helper(s, idx + 1, s1, s2, res);
        s1.pop_back();

        // Include s[idx] in s2
        s2.push_back(s[idx]);
        helper(s, idx + 1, s1, s2, res);
        s2.pop_back();

        // Exclude s[idx] from both s1 and s2
        helper(s, idx + 1, s1, s2, res);
    }

    int maxProduct(string s) {
        string s1 = "", s2 = "";
        int res = 0;
        helper(s, 0, s1, s2, res);
        return res;
    }
};
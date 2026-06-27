class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> need(128, 0);

        for (char c : t) need[c]++;

        int required = t.size(); // total chars needed (not unique)

        int l = 0, r = 0;
        int minLen = INT_MAX, start = 0;

        while (r < s.size()) {

            if (need[s[r]] > 0) {
                required--;
            }
            need[s[r]]--;

            // valid window
            while (required == 0) {

                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                need[s[l]]++;

                if (need[s[l]] > 0) {
                    required++;
                }

                l++;
            }

            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
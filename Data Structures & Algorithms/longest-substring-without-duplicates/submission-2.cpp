class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int l = 0, r = 0, n = s.size();
        int longest = 0;

        while (r < n) {
            if (freq[s[r]] > 0) {
                freq[s[l]]--;   
                l++;
            } else {
                freq[s[r]]++;
                r++;
            }

            longest = max(longest, r - l);
        }

        return longest;
    }
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> main(26, 0), sec(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            main[s1[i] - 'a']++;
            sec[s2[i] - 'a']++;
        }

        int l = 0;
        for (int r = s1.size(); r < s2.size(); r++) {

            if (main == sec) return true;

            sec[s2[l] - 'a']--;
            l++;

            sec[s2[r] - 'a']++;
        }

        return main == sec;
    }
};
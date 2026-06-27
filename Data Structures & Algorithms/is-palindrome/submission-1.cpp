class Solution {
public:
    bool isPalindrome(string s) {
        // convert all chars to lowercase and remove spaces
        for (char& c : s) {
            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) {
            return !std::isalnum(c); // Return true if character is NOT alphanumeric
            }), s.end());

        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            else l++, r--;
        }
        return true;
    }
};

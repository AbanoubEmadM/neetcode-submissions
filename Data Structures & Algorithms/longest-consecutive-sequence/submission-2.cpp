class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.empty()) return 0;

        map<int,int> elements;

        for (int num : nums)
            elements[num]++;

        int longest = 1;
        int count = 1;

        auto prev = elements.begin();
        auto it = prev;
        ++it;

        for (; it != elements.end(); ++it) {

            if (it->first - prev->first == 1)
                count++;
            else
                count = 1;

            longest = max(longest, count);
            prev = it;
        }

        return longest;
    }
};
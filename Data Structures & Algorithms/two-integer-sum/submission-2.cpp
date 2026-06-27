class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;  // val -> index
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            indices[nums[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];

            if (indices.count(diff) && indices[diff] != i) {
                return {i, indices[diff]};
            }
        }
    return {};
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int,int> freq;

        for(int n : nums)
            freq[n]++;

        vector<pair<int,int>> arr(freq.begin(), freq.end());

        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        vector<int> res;

        for(int i = 0; i < k; i++)
            res.push_back(arr[i].first);

        return res;
    }
};
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> carPair;
        for (int i = 0; i < position.size(); i++)
        {
                carPair.push_back({position[i], speed[i]});
        }
        sort(carPair.rbegin(), carPair.rend());
        vector<double> stack;
        for (auto &p : carPair)
        {
                stack.push_back((double)(target-p.first)/p.second);

            if (stack.size() >= 2 &&
                stack.back() <= stack[stack.size() - 2])
            {
                stack.pop_back();
            }
        }
        return stack.size();

    }
};

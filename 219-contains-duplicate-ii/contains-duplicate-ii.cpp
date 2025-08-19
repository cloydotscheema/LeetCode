class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> pres;
        for (int i = 0; i < nums.size(); i++) {
            if (pres.count(nums[i]) && i - pres[nums[i]] <= k) {
                return true;
            }
            pres[nums[i]] = i;
        }
        return false;
    }
};

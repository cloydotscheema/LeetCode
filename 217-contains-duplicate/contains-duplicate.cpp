class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> pres;
        for(int n : nums) {
            if(pres.count(n)) return true;
            pres.insert(n);
        }
        return false;
    }
};
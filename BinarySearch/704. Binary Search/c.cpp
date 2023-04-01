class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums.begin(), nums.end(), target)? \
            distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target)):-1;
    }
};
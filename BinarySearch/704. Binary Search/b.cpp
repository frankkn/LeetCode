class Solution {
public:

    pair<int,int> binarySearch(int L, int R, function<bool(int)> check){
        if(!check(L))   return {L-1, L};
        if(check(R))    return {R, R+1};
        while(L+1 < R){
            int M = (L+R)/2;
            if(check(M)){
                L = M;
            }else{
                R = M;
            }
        }
        return {L, R};
    }

    int search(vector<int>& nums, int target) {
        auto check = [&](int idx){return nums[idx] <= target; };
        auto [L, R] = binarySearch(0, nums.size()-1, check);
        return L < 0 ? -1: nums[L] == target ? L: -1;
    }
};
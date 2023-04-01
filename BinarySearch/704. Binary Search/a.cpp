class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size()-1;
        while(L < R){
            int M = (L+R)/2;
            if(target <= nums[M]){
                R = M;
            }else{
                L = M+1;
            }
        }
        return nums[L] == target? L: -1;
    }
};
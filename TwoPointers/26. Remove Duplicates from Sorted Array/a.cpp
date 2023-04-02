class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j;
        i = j = 0;    
        while(true){
            if(j >= nums.size()){
                break;
            } 
            if(nums[j] == nums[i]){
                ++j;
            }else{
                i++;
                swap(nums[j], nums[i]);
                j++;
            }
        }
        return i+1;
    }
};
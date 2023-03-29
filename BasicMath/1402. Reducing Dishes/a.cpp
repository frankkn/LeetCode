class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        if(sat.back() < 0)  return 0;
        int n = sat.size(), tmp = n;
        vector<int> nums(n); iota(nums.begin(), nums.end(), 1);
        int _max = 0;
        auto it = sat.begin();
        int prev_sum = 0;
        int co = 0;
        for(int i = 0; i < n; ++i){
            co += sat[i] * (i+1);
        }
        while(tmp--){
            co = co - prev_sum;
            _max = max(_max, co);
            prev_sum = accumulate(it, sat.end(), 0);;
            it++;
        }
        return _max;
    }
};
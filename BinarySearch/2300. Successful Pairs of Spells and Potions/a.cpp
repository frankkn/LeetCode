class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(auto& s: spells){
            long long value = (long long)ceil( (double)success / (double)s );
            if(binary_search(potions.begin(), potions.end(), value)){
                ans.emplace_back(distance(lower_bound(potions.begin(), potions.end(), value), potions.end()));
            }else if(value > *potions.rbegin()){
                ans.emplace_back(0);
            }else if(value < *potions.begin()){
                ans.emplace_back(potions.size());
            }else{
                ans.emplace_back(distance(lower_bound(potions.begin(), potions.end(), value), potions.end()));
            }
        }
        return ans;
    }
};
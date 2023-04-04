class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, int> M;
        int cnt = 1;
        for(auto it = s.begin(); it != s.end(); ++it){
            if(M.find(*it) == M.end()){
                M.emplace(*it, 1);
            }else{
                cnt++;
                M.clear();
                M.emplace(*it, 1);
            }
        }
        return cnt;
    }
};